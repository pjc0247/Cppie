#pragma once

#pragma warning(disable :4996)

#include <windows.h>
#include <assert.h>
#include <time.h>
#include <list>
#include <string>
#include <vector>
#define MAX_STRING	129
#define MAX_KEY		1296
#define MAX_STP		500

using namespace std;

template <typename Ty>
class arystack
{
private:
	int stack_size;
	Ty* stack_ary;
	int stack_count;

public:
	arystack(int ary_size)
	{
		stack_ary = new Ty[ary_size];
		stack_size = ary_size;
		stack_count=0;
	}
	~arystack()
	{
		delete[] stack_ary;
	}

	void push(const Ty& vr)
	{
		assert( stack_count != stack_size );
		stack_ary[stack_count++] = vr;
	}

	Ty pop()
	{
		assert( stack_count != 0);
		return stack_ary[--stack_count];
	}

	int size() const { return stack_count; }
	bool empty() const { return stack_count == 0 ? true : false; }
	Ty peek()
	{
		assert(stack_count != 0);
		return stack_ary[stack_count-1];
	}
	void clear() { stack_count=0; }
};


static int chr2key(char ch1, char ch2)
{
	int keyval;

	if ( ch1>='A' && ch1 <= 'Z' ) keyval = (ch1-'A'+10) * 36;
	else if(ch1>='0' && ch1 <= '9') keyval = (ch1-'0') * 36;
	else assert(0);

	if ( ch2>='A' && ch2 <= 'Z' ) keyval += (ch2-'A'+10);
	else if(ch2>='0' && ch2 <= '9') keyval += (ch2-'0');
	else assert(0);

	return keyval;
}


// BMS 헤더섹션 정보
struct BMSHEADERSECTION
{
	int player;
	char title[MAX_STRING];
	char artist[MAX_STRING];
	char genre[MAX_STRING];
	float bpm;
	int playlevel;
	int rank;
	int total;
	int volwav;
	char midifile[MAX_STRING];
	char wav[MAX_KEY][MAX_STRING];
	char bmp[MAX_KEY][MAX_STRING];
	char stagefile[MAX_STRING];
	char videofile[MAX_STRING];
	struct 
	{
		short bmpno;
		int x1,y1,x2,y2;
		int targetx,targety;
	} bga[MAX_KEY];
	float bpmch[MAX_KEY];
	int stop[MAX_KEY];
	struct  
	{
		short measure ,spot;
		int timetick;
	} stp[MAX_STP];
	short stpcount;

	bool lntype1;
	bool lntype2;
	short lnobj;

	// not support #EXTCHR
};

class CHANNELQUEUE
{
public:
	struct QueueNode
	{
		short measure;
		vector<short> data_ary;
	};

public:
	short channel;
	QueueNode* queue_ary;
	QueueNode null_node;
	size_t queue_count ,queue_capacity , deque_pos;

public:
	CHANNELQUEUE()
	{
		channel=0;
		queue_ary=0;
		queue_count=0;
		queue_capacity=0;
		deque_pos=0;

		null_node.measure = -1;
	}
	~CHANNELQUEUE()
	{
		clear();
	}

private:
	friend class BMSDATASECTION;
	void set_channel(short _channel)
	{
		this->channel = _channel;
	}
	void first_assign(size_t sz)
	{
		if(queue_ary==NULL) { queue_ary = new QueueNode[sz]; queue_capacity = sz; }
		
	}

	void clear()
	{
		if(queue_ary) { delete[] queue_ary; queue_ary=0; }
		channel=0;queue_count=0; queue_capacity=0; deque_pos=0;
	}

	void enqueue(short measure, vector<short> &data_ary)
	{
		if ( is_full()  ) return;
		
		queue_ary[queue_count].measure = measure;
		queue_ary[queue_count].data_ary.insert(
			queue_ary[queue_count].data_ary.end(),
			data_ary.begin(),data_ary.end()
			);

		queue_count++;
	}
	bool is_full()
	{
		return queue_count == queue_capacity ? true : false;
	}
public:
	short channel_value() const { return channel; }
	bool is_empty()
	{
		return deque_pos >= queue_count ? true : false;
	}
	QueueNode* dequeue()
	{
		if(is_empty()) return NULL;

		return &(queue_ary[deque_pos++]);
	}
	QueueNode* peek()
	{
		if(is_empty()) return NULL;
		return &(queue_ary[deque_pos]);
	}
};

class CHANNEL2QUEUE
{
public:
	struct QueueNode2
	{
		short measure;
		float data;
	};

private:
	short channel;
	QueueNode2* queue_ary;
	size_t queue_count ,queue_capacity , deque_pos;

public:
	CHANNEL2QUEUE()
	{
		channel=2;
		queue_ary=0;
		queue_count=0;
		queue_capacity=0;
		deque_pos=0;
	}
	~CHANNEL2QUEUE()
	{
		clear();
	}
private:
	friend class BMSDATASECTION;
	void first_assign(size_t sz)
	{
		if(!queue_ary) { queue_ary = new QueueNode2[sz]; queue_capacity = sz; }
	}

	void clear()
	{
		if(queue_ary) { delete[] queue_ary; queue_ary=0; }
		channel=0;queue_count=0; queue_capacity=0; deque_pos=0;
	}

	void enqueue(short measure, float data)
	{
		if ( is_full()  ) return;

		queue_ary[queue_count].measure = measure;
		queue_ary[queue_count++].data = data;
	}

	bool is_full()
	{
		return queue_count == queue_capacity ? true : false;
	}

public:
	short channel_value() const { return channel; }
	bool is_empty()
	{
		return deque_pos >= queue_count ? true : false;
	}
	QueueNode2* peek()
	{
		if(is_empty()) return NULL;
		return &(queue_ary[deque_pos]);
	}
	QueueNode2* dequeue()
	{
		if(is_empty()) return NULL;

		return &(queue_ary[deque_pos++]);
	}
};



// 데이터 섹션
class BMSDATASECTION
{
	const static short DATA_NEWLINE = -2;
	struct dsnode // data section node
	{
		short measure;	// 마디
		char channel;	// 채널
		vector<short> data_ary;	// 데이터

		dsnode* llink;
		dsnode* rlink;
	} *ds_head , *ds_tail;

	int max_measure;	// 마디 최고값
	int dsnode_count;	// 데이터섹션 노드 갯수
	size_t channel_node_count[256];

	friend class BmsParser;

	
	void _add_data(short measure,char channel , const char* src_data, int data_count)
	{
		dsnode* pNode = ds_tail , *pNext=0;

		vector<short> src_db;
		src_db.reserve(80);
		
		// 소스를 만든다.

		if(channel == 2)	// 2 채널은 데이터로 실수를 받는다.
		{
			data_count = 2;
			float ftmp = (float)atof(src_data);
			union 
			{
				float tv;
				short _s1,_s2;
			} uni;
			
			uni.tv = ftmp;

			src_db.push_back(uni._s1);
			src_db.push_back(uni._s2);
		}
		else
		{
			for(int i=0;i<data_count;i++)
			{
				src_db.push_back( (short) chr2key( src_data[2*i] , src_data[(2*i) + 1] ) );
			}
		}

		while(pNode)
		{
			if(pNode->measure == measure &&
				pNode->channel == channel)
			{
				break;
				// 데이터 한줄 추가. 
				/*
				size_t origin_size = pNode->data_ary.size();
								pNode->data_ary.reserve( origin_size + data_count + 1);
								pNode->data_ary.push_back(DATA_NEWLINE); 
								pNode->data_ary.insert(pNode->data_ary.end(),src_db.begin(),src_db.end());
								return;*/
				
			}
			else if(pNode->measure == measure) { if(pNode->channel < channel) break; }
			else if(pNode->measure < measure) break;

			pNext=pNode;
			pNode=pNode->llink;
		}

		// 마디 최대값을 변경
		max_measure = (max_measure < measure) ? measure : max_measure;

		// 새로운 데이터 생성
		dsnode* pTmp = new dsnode;
		pTmp->channel = channel;
		pTmp->measure = measure;
		pTmp->data_ary.insert(pTmp->data_ary.end(),src_db.begin(),src_db.end());

		// 삽입과정
		
		if(pNext==0)
		{
			pTmp->llink = pNode;
			pTmp->rlink = NULL;
			if(pNode) pNode->rlink = pTmp;
			ds_tail=pTmp;
			if(dsnode_count == 0) ds_head=ds_tail;
		}
		else
		{
			pNext->llink = pTmp;
			pTmp->rlink = pNext;
			pTmp->llink = pNode;
			if(pNode) pNode->rlink = pTmp;

			if(ds_head == pNext) ds_head=pTmp;
		}

		channel_node_count[channel]++;
		dsnode_count++;
	}

public:
	BMSDATASECTION()
	{
		ds_head=0;
		ds_tail=0;
		max_measure=0;
		dsnode_count=0;
		memset(channel_node_count,0,sizeof(size_t) * 256 );
	}
	~BMSDATASECTION()
	{
		Clear();
	}

	void Clear()
	{
		dsnode* pNode, *pDel;
		pNode=ds_head;

		while(pNode)
		{
			pDel = pNode;
			pNode= pNode->rlink;
			delete pDel;
		}

		ds_head=ds_tail=0;
		max_measure=0;
		dsnode_count=0;
		memset(channel_node_count,0,sizeof(size_t) * 256 );
	}

	void GetChannelQueue(short channel ,CHANNELQUEUE& rOut)
	{
		if(channel == 2) return;
		rOut.clear();
		if(channel_node_count[channel] == 0) return;
		rOut.set_channel(channel);
		rOut.first_assign(channel_node_count[channel]);
		
		dsnode* pNode=ds_head;
		while(pNode)
		{
			if(pNode->channel == channel)
			{
				rOut.enqueue(pNode->measure,pNode->data_ary);
			}
			pNode = pNode->rlink;
		}
	};

	void GetChannel2Queue(CHANNEL2QUEUE& rOut)
	{
		rOut.clear();
		if(channel_node_count[2] == 0) return;
		rOut.first_assign(channel_node_count[2]);

		dsnode* pNode=ds_head;

		while(pNode)
		{
			if(pNode->channel == 2)
			{
				union 
				{
					float fout;
					short s1,s2;
				} uni;
				uni.s1 = pNode->data_ary[0];
				uni.s2 = pNode->data_ary[1];
				rOut.enqueue(pNode->measure,uni.fout);
			}
			pNode = pNode->rlink;
		}
	}
};


class BmsParser
{
public:
	static int LoadFromFile(LPCSTR fileName,BMSHEADERSECTION& ref_header)
	{
		int retCode;

		retCode = _PreProcessing(fileName);
		retCode &= _FindHeaderSection(ref_header);

		command.clear();
		return retCode;
	}
	static int LoadFromFile(LPCSTR fileName,BMSDATASECTION& ref_data)
	{
		int retCode;

		retCode = _PreProcessing(fileName);
		retCode &= _FindDataSection(ref_data);

		command.clear();
		return retCode;
	}
	static int LoadFromFile(LPCSTR fileName,BMSHEADERSECTION& ref_header,BMSDATASECTION& ref_data)
	{
		int retCode;

		retCode = _PreProcessing(fileName);
		retCode &= _FindHeaderSection(ref_header);
		retCode &= _FindDataSection(ref_data);

		command.clear();
		return retCode;
	}

private:
	static int _PreProcessing(LPCSTR fileName)
	{
		FILE* file=fopen(fileName,"r");
		if(!file) return 0;
		
		char line[1024];
		char* pline;

		int rndnum=0;
		bool disregard=false;
		arystack<char> ifstack(100);	// if =1 else =2
		
		command.clear();
		srand((unsigned)time(NULL));
		
		while( (pline = fgets(line,1023,file)) )
		{
			if(*(pline++) != '#') continue;
			
			if( strncmp(pline,"RANDOM",6) == 0) 
			{
				int n;
				sscanf(pline+6,"%d",&n);
				rndnum = (rand() % n) + 1;
			}
			else if( strncmp(pline,"IF",2) == 0)
			{
				int n;
				sscanf(pline+2,"%d",&n);
				if(n != rndnum) disregard=true; 
				
				// 중첩 if 문은 문법상 오류
				if( !ifstack.empty()  ) return 0;

				ifstack.push(1);
			}
			else if( strncmp(pline,"ELSE",4) == 0)
			{
				if(ifstack.size() != 1 || ifstack.peek() != 1) return 0;
				disregard = disregard==true ? false : true;
				ifstack.push(2);
			}
			else if( strncmp(pline,"ENDIF",5) == 0)
			{
				if(ifstack.empty()) return 0;
				ifstack.clear();
				disregard=false;
			}
			else
			{
				if(disregard == true ) continue;
				command.push_back(string(pline));
			}
		}

		fclose(file);
		return 1;
	}
	static int _FindHeaderSection(BMSHEADERSECTION& ref_header)
	{
		int t0;
		const char* pline;
		memset(&ref_header,0,sizeof(BMSHEADERSECTION));
		
		// MSVC 2003 이상에서만 되는 키워드 : for each
		for each(const string& cmd in command)
		{
			pline = cmd.c_str();

			
			if(strncmp(pline,"PLAYER",6) == 0)
			{
				sscanf(pline+6,"%d",&t0);
				ref_header.player = t0;
			}
			else if(strncmp(pline,"TITLE",5) == 0)
			{
				pline+=5;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.title,pline);
				_RemoveNullString(ref_header.title);
			}
			else if(strncmp(pline,"ARTIST",6) == 0)
			{
				pline+=6;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.artist,pline);
				_RemoveNullString(ref_header.artist);
			}
			else if(strncmp(pline,"GENRE",5) == 0)
			{
				pline+=5;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.genre,pline);
				_RemoveNullString(ref_header.genre);
			}
			else if(strncmp(pline,"BPM",3) == 0)
			{
				char ch = *( pline+3 );

				// BPMxx n case
				if((ch >= '0' && ch <= '9') ||
				   (ch >= 'A' && ch <= 'Z') )
				{
					float val;
					int keyval = chr2key(ch, *(pline+4));
					sscanf(pline+5,"%f",&val);
					ref_header.bpmch[keyval] = val;
				}

				// BPM n case
				else
				{
					float val;
					sscanf(pline+3,"%f",&val);
					ref_header.bpm = val;
				}
			}
			else if(strncmp(pline,"PLAYLEVEL",9) == 0)
			{
				sscanf(pline+9,"%d",&t0);
				ref_header.playlevel = t0;
			}
			else if(strncmp(pline,"RANK",4) == 0)
			{
				sscanf(pline+4,"%d",&t0);
				ref_header.rank = t0;
			}
			else if(strncmp(pline,"TOTAL",5) == 0)
			{
				sscanf(pline+5,"%d",&t0);
				ref_header.total= t0;
			}
			else if(strncmp(pline,"VOLWAV",6) == 0)
			{
				sscanf(pline+6,"%d",&t0);
				ref_header.volwav=t0;
			}
			else if(strncmp(pline,"MIDIFILE",8) == 0)
			{
				pline+=8;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.midifile,pline);
				_RemoveNullString(ref_header.midifile);
			}
			else if(strncmp(pline,"WAV",3) == 0)
			{
				int keyval = chr2key( *(pline+3) , *(pline+4) );
				pline+=5;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.wav[keyval],pline);
				_RemoveNullString(ref_header.wav[keyval]);
			}
			else if(strncmp(pline,"BMP",3) == 0)
			{
				int keyval = chr2key( *(pline+3) , *(pline+4));
				pline+=5;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.bmp[keyval],pline);
				_RemoveNullString(ref_header.bmp[keyval]);
			}
			else if(strncmp(pline,"STAGEFILE",9) == 0)
			{
				pline+=9;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.stagefile,pline);
				_RemoveNullString(ref_header.stagefile);
			}
			else if(strncmp(pline,"VIDEOFILE",9) == 0)
			{
				pline+=9;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				strcpy(ref_header.videofile,pline);
				_RemoveNullString(ref_header.videofile);
			}
			else if(strncmp(pline,"BGA",3) == 0)
			{
				int keyval1 = chr2key( *(pline+3) , *(pline+4));

				pline+=5;
				while((*pline ==' ') && (*pline !='\0')) pline++;
				short bmpno = chr2key( *(pline) , *(pline+1));

				int x1,x2,y1,y2,tarx,tary;

				sscanf(pline+2,"%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&tarx,&tary);

				ref_header.bga[keyval1].bmpno = bmpno;
				ref_header.bga[keyval1].x1 = x1;
				ref_header.bga[keyval1].x2 = x2;
				ref_header.bga[keyval1].y1 = y1;
				ref_header.bga[keyval1].y2 = y2;
				ref_header.bga[keyval1].targetx = tarx;
				ref_header.bga[keyval1].targety = tary;
			}
			else if(strncmp(pline,"STOP",4) == 0)
			{
				int keyval = chr2key( *(pline+4) , *(pline+5) );
				sscanf(pline+6,"%d",&t0);
				ref_header.stop[keyval] = t0;
			}
			else if(strncmp(pline,"STP",3) == 0)
			{
				char tok1[5]={0};
				const char* pt1= pline+3;
				short measure, spot;

				pline+=3;
				while( *pline != '.' && *pline != '\0') pline++;

				strncpy(tok1,pt1,pline-pt1);

				measure = (short)atoi(tok1);
				sscanf(pline+1,"%d %d",&spot,&t0);
				
				ref_header.stp[ref_header.stpcount].measure = measure;
				ref_header.stp[ref_header.stpcount].spot = spot;
				ref_header.stp[(ref_header.stpcount)++].timetick = t0;
			}
			else if(strncmp(pline,"LNTYPE",6) == 0)
			{
				sscanf(pline+6,"%d",&t0);
				if(t0 == 1) ref_header.lntype1=true;
				else if(t0 == 2) ref_header.lntype2=true;
			}
			else if(strncmp(pline,"LNOBJ",5) == 0)
			{
				sscanf(pline+5,"%d",&t0);
				ref_header.lnobj = (short)t0;
			}

		}

		return 1;
	}

	static int _FindDataSection(BMSDATASECTION& ref_data)
	{
		int measure , channel;
		const char* pline;
		char* errptr;
		char chstr[3]={0} , mestr[4]={0};
		
		for each(const string& cmd in command)
		{
			pline = cmd.c_str();

			if(*pline < '0' || *pline > '9' )			continue;
			if(*(pline+1) < '0' || *(pline+1) > '9' )	continue;
			if(*(pline+2) < '0' || *(pline+2)> '9' )	continue;

			mestr[0]= *(pline);
			mestr[1]= *(pline+1);
			mestr[2]= *(pline+2);
			chstr[0]= *(pline+3);
			chstr[1]= *(pline+4);
			
			measure = atoi(mestr);
			channel = (int)strtol(chstr,&errptr,16);

			pline+=6;

			// 데이터 획득
			int datalen = (int) ( strlen(pline) / 2 );
			ref_data._add_data(measure,channel,pline,datalen);
		}
		return 1;
	}



	static void _RemoveNullString(char* str)
	{
		size_t _len = strlen(str);
		for(size_t i=0;i<_len; i++)
			if(str[i] <= 31 && str[i] >= 0 ) str[i] = 0;
	}
	static list<string> command;
};


list<string> BmsParser::command;
