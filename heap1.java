import java.util.*;
public class heap1
{
	public static double[] calcMedian(int[] a)
	{
		
		PriorityQueue<Integer> higher= new PriorityQueue();
		PriorityQueue<Integer> lower= new PriorityQueue(new Comparator<Integer>()
		{
			public int compare(Integer a,Integer b)
			{
				return (-1*a.compareTo(b));
			}
		});
		double[] res=new double[a.length];
		for(int i=0;i<a.length;i++)
		{
			addElement(lower,higher,a[i]);
			reBalance(lower,higher);
			res[i]=median(lower,higher);
		}
		return res;
	}
	public static void addElement(PriorityQueue<Integer> lower,PriorityQueue<Integer> higher,int x)
	{
		if(lower.size()==0)
		{
			lower.add(x);
		}
		else if(x<lower.peek())
		{
			lower.add(x);
		}
		else
		{
			higher.add(x);
		}
	}
	public static void reBalance(PriorityQueue<Integer> lower,PriorityQueue<Integer> higher)
	{
		PriorityQueue<Integer> lower_size=lower.size()>higher.size()?higher:lower;
		PriorityQueue<Integer> higher_size=lower.size()>higher.size()?lower:higher;
		if((higher_size.size()-lower_size.size())>=2)
		{
			lower_size.add(higher_size.poll());
		}
	}
    public static double median(PriorityQueue<Integer> lower,PriorityQueue<Integer> higher)
	{
		PriorityQueue<Integer> lower_size=lower.size()>higher.size()?higher:lower;
		PriorityQueue<Integer> higher_size=lower.size()>higher.size()?lower:higher;
		int len=lower.size()+higher.size();
		
		if(lower.size()== higher.size()){
			return ((double)higher_size.peek()+lower_size.peek())/2;
		}
		else
			return higher_size.peek();
			
	}
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=s.nextInt();
		//heap1 obj=new heap1();
		double[] res=calcMedian(arr);
		System.out.println();
		for(int i=0;i<n;i++)
			System.out.println(res[i]);
	}
}