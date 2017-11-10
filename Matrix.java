/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
public class Matrix
{
	public static void dijkstras(ArrayList<ArrayList<Integer>> array,int start)
	{
		Boolean[] visited=new Boolean[array.size()];
		for(int i=0;i<visited.length;i++)
		{
			visited[i]=false;
		}
		Integer[] distance=new Integer[array.size()];
		for(int i=0;i<distance.length;i++)
		{
			distance[i]=Integer.MAX_VALUE;
		}
		distance[start]=0;
		int flag=0;
		int min_distance=Integer.MAX_VALUE,min_distance_index=0;
		while(true)
		{
			for(int i=0;i<visited.length;i++)
			{
				if(visited[i]==false)
					flag=1;
				if(visited[i]==false && distance[i]<min_distance)
				{
					min_distance=distance[i];
					min_distance_index=i;
				}
			}
			if(flag==0)
			{
				break;
			}
			flag=0;
			min_distance=Integer.MAX_VALUE;
			ArrayList<Integer> obj=array.get(min_distance_index);
			visited[min_distance_index]=true;
			for(int i=0;i<obj.size();i++)
			{
				if(obj.get(i)!=0)
				{
					if(distance[i]>distance[min_distance_index]+array.get(i).get(min_distance_index))
					{
						distance[i]=distance[min_distance_index]+array.get(i).get(min_distance_index);
					}
				}
			}
		}
		for(int i=0;i<distance.length;i++)
			System.out.println(distance[i]);
	}
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		System.out.println("ENTER THE NO OF VERTICES");
		int n=s.nextInt();
		ArrayList<ArrayList<Integer>> array=new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<n;i++)
		{
			array.add(new ArrayList<Integer>(Collections.nCopies(n,0)));
		}
		System.out.println("ENTER THE NO OF EDGES YOU WANT TO CONNECT");
		int m=s.nextInt();
		
		for(int i=0;i<m;i++)
		{
			System.out.println("ENTER THE VALUES");
			int a=s.nextInt();
			int b=s.nextInt();
			int c=s.nextInt();
			array.get(a).set(b,c);
			array.get(b).set(a,c);
		}
		for(int i=0;i<array.size();i++)
		{
			for(int j=0;j<array.size();j++)
			{
				System.out.print(array.get(i).get(j)+" ");
			}
			System.out.println();
		}
		dijkstras(array,0);
	}
}
