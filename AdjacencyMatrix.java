/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package adjacencymatrix;
import java.util.*;
public class AdjacencyMatrix
{
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
			array.get(a).set(b,1);
			array.get(b).set(a,1);
		}
		for(int i=0;i<array.size();i++)
		{
			for(int j=0;j<array.size();j++)
			{
				System.out.print(array.get(i).get(j)+" ");
			}
			System.out.println();
		}
		
	}
}
