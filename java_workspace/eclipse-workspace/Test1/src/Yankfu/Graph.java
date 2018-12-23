package Yankfu;
package Yankfu;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;
import java.text.DecimalFormat;

public class Graph {
	public static void main(String[] args)
	{
		Graph gragh = new Graph();
		gragh.showGragh();
		gragh.degree();
		gragh.DFSTraverse();
		System.out.println();
		gragh.BFSTraverse();
	}
}
	
	public class Graph
	{
		AdjMatrix G;
		
		private boolean[] visited;

		public Gragh(){
			Scanner sc = new Scanner(System.in);
			System.out.println("���붥�����ͱ�����");
			int vertexnum = sc.nextInt();
			int arcnum = sc.nextInt();
			
			G = new AdjMatrix(vertexnum,arcnum);
			
			System.out.println("���붥����Ϣ��");
			for(int i = 1;i <= G.vertexnum;i++)
			{
				G.vertex[i] = sc.next().charAt(0);
			}
			
			//��ʼ���ڽӾ���
			for(int i = 1;i <= G.vertexnum;i++)
			{
				for(int j = 1;j <= G.vertexnum;j++)
				{
					G.arcs[i][j] = 0;
				}
			}
			
			//��������ͼ
			System.out.println("����ͷ��β���㣺");
		    int head = 0,tail = 0;
		    for(int i = 0;i < G.arcnum;i++)
		    {
		    	char vertex_head = sc.next().charAt(0);
			    char vertex_tail = sc.next().charAt(0);
		    	for(int j = 1;j <= G.vertexnum;j++)
		    	{
			    	if(G.vertex[j] == vertex_head)
			    	{
			    		head = j;
			    		for(int k = 1;k <= G.vertexnum;k++)
			    		{
					        if(G.vertex[k] == vertex_tail)
					    		tail = k;
					    }
				    }
			    }
		    	G.arcs[head][tail] = 1;
		    }
			sc.close();
		}
		
		/*
		 * ���ĳ��ȡ���ȡ���
		 */
		public void degree() {
			for(int i = 1;i <= G.vertexnum;i++)
			{
				int count_out = 0; int count_in = 0;int count = 0;
				for(int j = 1;j <= G.vertexnum;j++)
				{
					if(G.arcs[j][i] == 1)
						count_in++;
					if(G.arcs[i][j] == 1)
						count_out++;
					count = count_in + count_out;
				}
				System.out.println(G.vertex[i] + " " + count_out + " " + count_in + " "
						+ count);
			}
			
		}
		
		private void DFS(int start) {
			visited = new boolean[G.vertexnum + 1];
			Stack<Integer> s = new Stack<>();
			s.push(start);
			System.out.print(G.vertex[start]);
			visited[start] = true;
			while(!s.empty())
			{
				int top = s.peek();
				boolean is_push = false;
				for(int i = 1;i <= G.vertexnum;i++)
				{
					if(G.arcs[top][i] == 1 && visited[i] == false) 
					{
						System.out.print(G.vertex[i]);
						visited[i] = true;
						s.push(i);
						is_push = true;
						break;
					}
				}
				if(is_push == false) {
					s.pop();
				}
			}	
		}
		
		public void DFSTraverse() {
			visited = new boolean[G.vertexnum + 1];
			for(int i = 1;i <= G.vertexnum;i++)
			{
				if(visited[i] == false)
					DFS(i);
			}
		}
		
		private void BFS(int start) {
			visited = new boolean[G.vertexnum + 1];
			Queue<Integer> q = new LinkedList<>();
			System.out.print(G.vertex[start]);
			visited[start] = true;
			q.add(start);
			while(!q.isEmpty())
			{
				int top = q.poll();
				for(int i = 1;i <= G.vertexnum;i++)
				{
					if(G.arcs[top][i] == 1 && visited[i] == false) 
					{
						System.out.print(G.vertex[i]);
						visited[i] = true;
						q.add(i);
					}
				}
			}	
		}
		public void BFSTraverse() {
			visited = new boolean[G.vertexnum + 1];
			for(int i = 1;i <= G.vertexnum;i++)
			{
				if(visited[i] == false)
					BFS(i);
			}
		}
		
		/*
		 * ��ӡ����ͼ
		 */
		public void showGragh(){
			System.out.print("   ");
			for (int i = 1; i <= G.vertexnum; i++)
			{//��ӡ������Ϣ
				System.out.print(G.vertex[i] + " ");
			}
			System.out.println();
			for (int i = 1; i <= G.vertexnum; i++)
			{//��ӡ�ڽӾ���
				System.out.print(G.vertex[i] + "  ");
				for (int j = 1; j <= G.vertexnum; j++)
				{
					System.out.print(G.arcs[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
	class AdjMatrix{
		final int MAX_VERTEX = 20;                              //��󶥵����
		int[][] arcs = new int[MAX_VERTEX][MAX_VERTEX];         //����Ϣ
		char[] vertex = new char[MAX_VERTEX];                   //������Ϣ
		int vertexnum;               //������
		int arcnum;                  //����
		AdjMatrix(int vertexnum,int arcnum) {
			this.vertexnum = vertexnum;
			this.arcnum = arcnum;
		}
	}