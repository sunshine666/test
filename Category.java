package book.model;

public class Category {
	private int id;
	private String name;
	private String author;
	private String arname;
	private String arage;
	private String arcountry;
	private String Publisher;
	private String PublishDate;
	private String price;
	
	public Category(){}
	
	public int getId()
	{
		return id;
	}
	
	public void setId(int id)
	{
		this.id=id;
	}
	
	public String getName()
	{
		return name;
	}
	
	public void setName(String name)
	{
		this.name=name;
	}
	
	public String getAuthor()
	{
		return author;
	}
	
	public void setAuthor(String author)
	{
		this.author=author;
	}
	
	public String getArname()
	{
		return arname;
	}
	
	public void setArname(String arname)
	{
		this.arname=arname;
	}
	
	public String getArcountry()
	{
		return arcountry;
	}
	
	public void setArcountry(String arcountry)
	{
		this.arcountry=arcountry;
	}
	
	public String getArage()
	{
		return arage;
	}
	
	public void setArage(String arage)
	{
		this.arage=arage;
	}
	
	public String getPublisher()
	{
		return Publisher;
	}
	
	public void setPublisher(String Publisher)
	{
		this.Publisher=Publisher;
	}
	
	public String getPublishDate()
	{
		return PublishDate;
	}
	
	public void setPublishDate(String PublishDate)
	{
		this.PublishDate=PublishDate;
	}

	public String getPrice()
	{
		return price;
	}
	
	public void setPrice(String price)
	{
		this.price=price;
	}
	

}
