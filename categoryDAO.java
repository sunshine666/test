package book.db;

import java.sql.*;
import javax.naming.*;
import java.util.*;

import book.model.Category;;

public class categoryDAO {
	private Connection conn;
	private Statement state;
	private Statement state1;
	private PreparedStatement pstate;
	private PreparedStatement pstate1;
	private ResultSet rs;
	private ResultSet rs1;
	
	public categoryDAO()
	{
		if(conn==null)
		{
			try
			{
				conn=DBpool.GetConnection();
			}
			catch(NamingException e)
			{
				e.printStackTrace();
			}
			catch(SQLException se)
			{
				se.printStackTrace();
			}
		}
			
	}
	
	public ArrayList<Category> getCategorylist()
	{
		ArrayList<Category> cl=new ArrayList();
		try
		{
			state=conn.createStatement();
			rs=state.executeQuery("select * from book");
			while(rs.next())
			{
				Category c=new Category();
				c.setId(rs.getInt("ISBN"));
				c.setName(rs.getString("Title"));
				c.setAuthor(rs.getString("AuthorID"));
				//System.out.println(c.getId());
				cl.add(c);
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				rs.close();
				state.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
		return cl;
	}
	
	public ArrayList<Category> searchCategorylist(String name)
	{
		ArrayList<Category> ck=new ArrayList();
		try
		{
			System.out.println("select * from book where AuthorID="+"'"+name+"'");
			state=conn.createStatement();
			rs=state.executeQuery("select * from book where AuthorID="+"'"+name+"'");
			while(rs.next())
			{
				Category c=new Category();
				c.setId(rs.getInt("ISBN"));
				c.setName(rs.getString("Title"));
				c.setAuthor(rs.getString("AuthorID"));
				//System.out.println(c.getId());
				ck.add(c);
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				rs.close();
				state.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
		return ck;
	}
	
	public Category getCategoryById(String id)
	{
		Category c=new Category();
		try
		{
			state=conn.createStatement();
			state1=conn.createStatement();
			rs=state.executeQuery("select * from book where ISBN="+id);
			if(rs.next())
			{
				System.out.println(rs.getString("AuthorID"));
				rs1=state1.executeQuery("select * from author where AuthorID="+rs.getString("AuthorID"));
				if(rs1.next())
				{
				c.setId(rs.getInt("ISBN"));
				c.setName(rs.getString("Title"));
				c.setAuthor(rs.getString("AuthorID"));
				c.setArname(rs1.getString("Name"));
				c.setArage(rs1.getString("Age"));
				c.setArcountry(rs1.getString("Country"));
				c.setPublisher(rs.getString("Publisher"));
				c.setPublishDate(rs.getString("PublishDate"));
				c.setPrice(rs.getString("Price"));
				}
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				rs1.close();
				rs.close();
				state.close();
				state1.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
		return c;
		
	}
	
	public int addCategory(Category c,String id)
	{
		int jg=0;
		try
		{
			state=conn.createStatement();
			rs=state.executeQuery("select AuthorID from author where AuthorID='"+c.getAuthor()+"'");
			//System.out.println("kk");
			if(rs.next())
			{
			//pstate1=conn.prepareStatement("update author set Name =?,Age=?,Country=? where AuthorID=?");
			//pstate1.setString(1, c.getArname());
			//pstate1.setString(2, c.getArage());
			//pstate1.setString(3, c.getArcountry());
			//pstate1.setString(4, c.getAuthor());
			//pstate1.executeUpdate();
			pstate=conn.prepareStatement("insert into book (ISBN,Title,AuthorID,Publisher,PublishDate,Price) values (?,?,?,?,?,?)");
			pstate.setString(1,id);
			pstate.setString(2,c.getName());
			pstate.setString(3,c.getAuthor());
			pstate.setString(4,c.getPublisher());
			pstate.setString(5,c.getPublishDate());
			pstate.setString(6,c.getPrice());
			jg=pstate.executeUpdate();
			//System.out.println("you");
			}
			else
			{
				pstate1=conn.prepareStatement("insert into author (AuthorID,Name,Age,Country) values (?,?,?,?)");
				pstate1.setString(1, c.getAuthor());
				pstate1.setString(2, c.getArname());
				pstate1.setString(3, c.getArage());
				pstate1.setString(4, c.getArcountry());
				pstate1.executeUpdate();
				pstate=conn.prepareStatement("insert into book (ISBN,Title,AuthorID,Publisher,PublishDate,Price) values (?,?,?,?,?,?)");
				pstate.setString(1,id);
				pstate.setString(2,c.getName());
				pstate.setString(3,c.getAuthor());
				pstate.setString(4,c.getPublisher());
				pstate.setString(5,c.getPublishDate());
				pstate.setString(6,c.getPrice());
				jg=pstate.executeUpdate();
				//System.out.println("you1");
				pstate1.close();
			}
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				rs.close();
				state.close();
				pstate.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
		return jg;
	}
	
	public int editCategory(Category c)
	{
		int jg=0;
		try
		{
			//System.out.println("select AuthorID from author where AuthorID='"+c.getAuthor()+"'");
			state=conn.createStatement();
			rs=state.executeQuery("select AuthorID from author where AuthorID='"+c.getAuthor()+"'");
			//System.out.println("kk");
			if(rs.next())
			{
			pstate1=conn.prepareStatement("update author set Name =?,Age=?,Country=? where AuthorID=?");
			pstate1.setString(1, c.getArname());
			pstate1.setString(2, c.getArage());
			pstate1.setString(3, c.getArcountry());
			pstate1.setString(4, c.getAuthor());
			pstate1.executeUpdate();
			pstate=conn.prepareStatement("update book set Title =?,AuthorID=?,Publisher=?,PublishDate=?,Price=? where ISBN=?");
			pstate.setString(1,c.getName());
			pstate.setString(2,c.getAuthor());
			pstate.setString(3,c.getPublisher());
			pstate.setString(4,c.getPublishDate());
			pstate.setString(5,c.getPrice());
			pstate.setInt(6,c.getId());
			jg=pstate.executeUpdate();
			//System.out.println("you");
			}
			else
			{
				pstate1=conn.prepareStatement("insert into author (AuthorID,Name,Age,Country) values (?,?,?,?)");
				pstate1.setString(1, c.getAuthor());
				pstate1.setString(2, c.getArname());
				pstate1.setString(3, c.getArage());
				pstate1.setString(4, c.getArcountry());
				pstate1.executeUpdate();
				pstate=conn.prepareStatement("update book set Title =?,AuthorID=?,Publisher=?,PublishDate=?,Price=? where ISBN=?");
				pstate.setString(1,c.getName());
				pstate.setString(2,c.getAuthor());
				pstate.setString(3,c.getPublisher());
				pstate.setString(4,c.getPublishDate());
				pstate.setString(5,c.getPrice());
				pstate.setInt(6,c.getId());
				jg=pstate.executeUpdate();
				//System.out.println("you1");
			}
			//System.out.println("m");
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				rs.close();
				pstate1.close();
				pstate.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
		//System.out.println(jg);
		return jg;
	}
	
	public int delCategory(String id)
	{
		int jg=0;
		try
		{
			state=conn.createStatement();
			jg=state.executeUpdate("delete from book where ISBN="+id);
		}
		catch(SQLException e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				state.close();
			}
			catch(SQLException e)
			{
				e.printStackTrace();
			}
		}
		return jg;
	}

}
