package book.db;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;
import java.util.ResourceBundle;

import javax.naming.*;


public class DBpool {
	private static Connection conn;
	
	public static Connection GetConnection() throws SQLException,NamingException
	{
		try
		{
			Properties p = new Properties(); 
			InputStream in = DBpool.class.getResourceAsStream("/1.properties");  
            p.load(in);  
            in.close(); 
            String url=p.getProperty("url"); 
			//String url="jdbc:mysql://localhost:3306/Í¼ÊéÊý¾Ý¿âbookdb";
			//String url="jdbc:mysql://w.rdc.sae.sina.com.cn:3307/app_sunaaaa";
		    String user="jj40kolo1w";
			String password="ymj4ji0m13kxjmh4x4l5z1k0w41lkiyjmh3w5mzj";
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			conn=DriverManager.getConnection(url,user,password);  
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return conn;
	}

}
