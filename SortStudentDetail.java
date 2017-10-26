/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sortstudentdetail;
import java.util.*;
/**
 *
 * @author Master
 */
class student
{
    int roll;
    double cgpa;
    String name;
  public student(int r,double grade,String name)
  {
      this.roll=r;
      this.cgpa=grade;
      this.name=name;
  }
}
class sortByRoll implements Comparator<student>
{
    public int compare(student a,student b)
    {
        return b.roll-a.roll;
    }
}
public class SortStudentDetail {

    public static void main(String[] args)
    {
          ArrayList<student> al=new ArrayList<student>();
          al.add(new student(23,9.0,"qwerty"));
          al.add(new student(13,6.0,"asdfgh"));
          al.add(new student(3,5.0,"zxc"));
          Collections.sort(al,new sortByRoll());
          Iterator itr=al.iterator();
          while(itr.hasNext())
          {
              student s=(student)itr.next();
              System.out.println(s.roll+" "+s.cgpa+" "+s.name);
          }
    }
}
