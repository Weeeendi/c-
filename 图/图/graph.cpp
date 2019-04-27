#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
typedef struct VertexNode  //�����ͷ���
{
    char data;
    struct ArcNode * firstarc;
}VertexNode;
typedef struct ArcNode  //�����
{
    char data;
    struct ArcNode * nextarc;
}ArcNode;
ArcNode * InSertArcNode(char name)
{
    ArcNode * p = new ArcNode;
    p->data = name;
    p->nextarc = NULL;
    return p;
}
VertexNode * AdjList()//�ڽ������ʾ��
{
    ArcNode * p=NULL;
    VertexNode * List_head = new VertexNode[9];
    int count = 0;
    List_head[count].data = 'A';
    p = List_head[count].firstarc = InSertArcNode('B');
    p = p->nextarc = InSertArcNode('D');
    p = p->nextarc = InSertArcNode('E');
    count++;
    List_head[count].data = 'B';
    p = List_head[count].firstarc = InSertArcNode('A');
    p = p->nextarc = InSertArcNode('C');
    p = p->nextarc = InSertArcNode('E');
    count++;
    List_head[count].data = 'C';
    p = List_head[count].firstarc = InSertArcNode('B');
    p = p->nextarc = InSertArcNode('F');
    count++;
    List_head[count].data = 'D';
    p = List_head[count].firstarc = InSertArcNode('A');
    p = p->nextarc = InSertArcNode('G');
    count++;
    List_head[count].data = 'E';
    p = List_head[count].firstarc = InSertArcNode('A');
    p = p->nextarc = InSertArcNode('B');
    p = p->nextarc = InSertArcNode('G');
    count++;
    List_head[count].data = 'F';
    p = List_head[count].firstarc = InSertArcNode('C');
    count++;
    List_head[count].data = 'G';
    p = List_head[count].firstarc = InSertArcNode('D');
    p = p->nextarc = InSertArcNode('E');
    p = p->nextarc = InSertArcNode('H');
    count++;
    List_head[count].data = 'H';
    p = List_head[count].firstarc = InSertArcNode('G');
    p = p->nextarc = InSertArcNode('I');
    count++;
    List_head[count].data = 'I';
    p = List_head[count].firstarc = InSertArcNode('H');

    return List_head;
}

void AdjMatrix(char arc[][9])
{
    for (int i = 0; i < 9; i++)   //��ʼ���ڽӾ���
        for (int j = 0; j < 9; j++)
        {
            arc[i][j] = 0;
        }
    arc[0][1] = arc[0][3] = arc[0][4] = 1;
    arc[1][0] = arc[1][2] = arc[1][4] = 1;
    arc[2][1] = arc[2][5] = 1;
    arc[3][0] = arc[3][6] = 1;
    arc[4][0] = arc[4][1] = arc[4][6] = 1;
    arc[5][2] = 1;
    arc[6][3] = arc[6][4] = arc[6][7] = 1;
    arc[7][6] = arc[7][8] = 1;
    arc[8][7] = 1;
}
void DFS_matrix(char G[][9],int i,bool *visited)  //���������������i��ͨ�����нڵ�
{
    visited[i] = true;  //����i�����ʣ���־��Ϊtrue
    for (int j = 0; j < 9; j++)
    {
        if (!visited[j] && G[i][j]==1)
        {   
            cout << vextex[j] << ",";
            DFS_matrix(G, j, visited); //�ݹ�
        }
    }
}
void DFS_AdjMatrix(char G[][9])  //�����������_�ڽ�����洢
{
    bool visited[9] = { 0 };  //��ʼ�����ʱ�־����
    for (int i = 0; i < 9; i++) //����Ƿ����нڵ㶼�����ʹ�
    {
        if (!visited[i])//����iδ�����ʹ������i���������������
        {
            cout << vextex[i]<<",";
            DFS_matrix(G, i, visited);//���������������i
        }
    }
}
void DFS_list(VertexNode * GRAPH, int i, bool *visited)
{
    visited[i] = true;  //����i�����ʣ���־��Ϊtrue
    cout << vextex[i] << ",";
    ArcNode * p = GRAPH[i].firstarc; //�ҵ���һ���ڽ�������
    while (p!=NULL)
    {
        int temp = p->data - 'A'; //����ڵ��λ��
        if (!visited[temp]) //����ڽӶ����Ƿ񱻷��ʹ�
            DFS_list(GRAPH, temp, visited); //��������������temp  
        p = p->nextarc;//���ݵ���һ���ڽӶ���
    }
}
void DFS_AdjList(VertexNode * GRAPH)  //�����������--�ڽ�����洢
{
    bool visited[9] = { 0 }; //��ʼ�����ʱ�־����
    for (int i = 0; i < 9; i++)//����Ƿ����нڵ㶼�����ʹ�
    {
        if (!visited[i])
        {
            DFS_list(GRAPH, i, visited);//���������������i
        }
    }
}
void BFS_list(VertexNode *GRAPH, int i, bool *visited, queue<char> &Q)
{
    cout << Q.front() << ","; 
    Q.pop(); //������
    /*���ʵ�����i�������ڽӵ�*/
    ArcNode *p = GRAPH[i].firstarc; //��һ���ڽ��
    while ( p!=NULL )  //���η��ʶ���i���ڽӵ�
    {
        /*(p->data - 'A')����������*/
        if (*(visited + (p->data - 'A')) == 0)//����ڽӵ��Ƿ񱻷��ʹ�
        {
            *(visited + (p->data - 'A')) = true;//���ʱ�־��1
            Q.push(p->data); //�ڽӵ�������ȶ���
        }
        p = p->nextarc;  
    }
    if (!Q.empty()) //�ݹ����������Ķ���
    {
        BFS_list(GRAPH, Q.front() - 'A', visited, Q);
    }
}
void BFS_AdjList(VertexNode *GRAPH)//���������������i--�ڽӱ�洢
{
    bool visited[9] = { 0 }; //���ʱ�־��ʼ��
    queue<char> Q; //���ȶ���
    for (int i = 0; i < 9; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;  //���ʱ�־��1
            Q.push(vextex[i]);   //���붥�����
            BFS_list(GRAPH, i, visited, Q); //���������������i
        }
    }
}
void BFS_KLevel(VertexNode * GRAPH, int i,int k) //������붥��iΪk�����ж���
{
    if (k==0) //���k=0������˶���
    {
        cout << GRAPH[i].data << endl;
        return;
    }
    queue<char> Q1; //�ѷ��ʶ���
    queue<unsigned int> Q2; //�ѷ��ʶ����붥��i�ľ���
    bool visited[9] = { 0 };//���ʱ�־
    visited[i] = true;   //����i��1
    Q1.push(vextex[i]); //�������
    Q2.push(0);  //�������

    while (!Q1.empty())
    {
        int index = Q1.front() - 'A';  //��������

        ArcNode *p = GRAPH[index].firstarc;//��һ���ڽӵ�
        int level = Q2.front(); 
        while (p!=NULL)
        {
            if (*(visited+(p->data-'A')) == 0)  //���û�б����ʹ�
            {
                *(visited + (p->data - 'A')) =true;//���ʱ�־��1
                Q1.push(p->data);  
                Q2.push(level + 1);  //����+1
                if (level + 1 == k)  //�жϾ���
                {
                    cout << p->data << ",";
                }
            }
            p = p->nextarc; 
        }
        Q1.pop();
        Q2.pop();
    }

}

int main()
{   

    VertexNode * GRAPH = AdjList();  //�ڽ����� 
    char G[9][9] = { 0 };//��ʼ��
    AdjMatrix(G);   //�ڽӾ���
    DFS_AdjMatrix(G); //DFS--�ڽӾ���
    cout <<"  DFS--�ڽӾ���"<< endl;
    DFS_AdjList(GRAPH); //DFS--�ڽ�����
    cout << "  DFS--�ڽ�����" << endl;
    BFS_AdjList(GRAPH); //BFS--�ڽ�����
    cout << "  BFS--�ڽ�����" << endl;
    cout << "------------" << endl;
    BFS_KLevel(GRAPH,1,2);//������붥��BΪ2�Ķ���
    cout << " ���붥��BΪ2�Ķ���" << endl;
	getchar();
    return 0;
}