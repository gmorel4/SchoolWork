import java.net.URL;


public class User {
	private String userName;
	private URL picLocation;
	
	public User (String userName, URL picLocation){
		this.userName = userName;
		this.picLocation = picLocation;
	}
	
	public User (String userName)
	{
		this.userName = userName;
	}
	
	public String getName (){
		return userName;
	}
	
	public URL getPic (){
		return picLocation;
	}


}
