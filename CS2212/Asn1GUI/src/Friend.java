import java.net.URL;


public class Friend {
	
	private String name;
	private URL profilePic;
	private int id;
	
	public Friend (String name, int id){
		this.name = name;
		this.id = id;
	}
	
	public String getName (){
		return name;
	}
	
	public URL getPic (){
		return profilePic;
	}
	
	public int getId (){
		return id;
	}
	
	public void setPic (URL pic)
	{
		profilePic = pic;
	}
}
