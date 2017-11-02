package Dfs;
import java.util.*;
public class Dfs
{
	public static void depthFirstSearch(ArrayList<LinkedList<Integer>> v,int s,boolean visited[])
	{
		visited[s]=true;
		for(int i=0;i<v.get(s).size();i++)
		{
			int index;
			index=v.get(s).get(i);
			if(visited[index]!=true)
			{
				depthFirstSearch(v,index,visited);
			}
		}
	}
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		System.out.println("ENTER THE NO OF VERTICES");
		int n=s.nextInt();
		ArrayList<LinkedList<Integer>> array=new ArrayList<LinkedList<Integer>>();
		for(int i=0;i<n;i++)
		{
			array.add(new LinkedList<Integer>());
		}
		System.out.println("ENTER THE NO OF EDGES YOU WANT TO CONNECT");
		int m=s.nextInt();
		for(int i=0;i<m;i++)
		{
			System.out.println("ENTER THE VALUES");
			int a=s.nextInt();
			int b=s.nextInt();
			array.get(a).add(b);
			array.get(b).add(a);
		}
		for(int i=0;i<array.size();i++)
		{
			LinkedList<Integer> a=array.get(i);
			System.out.print(i+": ");
	
			for(int j=0;j<a.size();j++)
			{
				System.out.print(a.get(j)+" ");
			}
			System.out.println();
		}
		boolean[] visited=new boolean[n];
		for(int i=0;i<n;i++)
			visited[i]=false;
		depthFirstSearch(array,0,visited);
		for(int i=0;i<n;i++)
                {
			System.out.println(visited[i]);
                }
		
	}
}
