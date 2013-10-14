import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.URL;

import javax.swing.*;

public class GUI extends FriendSearch{
	
	private JPanel outerPanel, friendInfoPanel, userInfoPanel, listPanel;
	private JList friendList;
	private JLabel userName, userPic, friendName, friendPic;
	private JButton getFriend;
	
	public GUI (){
		
		initializeElements();
		userInfoPanel.setLayout(new BoxLayout(userInfoPanel, BoxLayout.X_AXIS));
		userName = new JLabel (getUserName());
		userName.setFont(new Font(userName.getFont().getFontName(), Font.BOLD, 18));
		userName.setForeground(Color.DARK_GRAY);
		userInfoPanel.add(userName);
		userInfoPanel.add(Box.createRigidArea(new Dimension(5,0)));
		userPic = new JLabel(new ImageIcon(getUserPic()));
		userInfoPanel.add(userPic);
		friendInfoPanel.setLayout(new BoxLayout(friendInfoPanel, BoxLayout.X_AXIS));
		outerPanel.add(userInfoPanel,BorderLayout.NORTH);
		outerPanel.add(friendInfoPanel,BorderLayout.CENTER);
		listPanel.setLayout(new BoxLayout(listPanel, BoxLayout.Y_AXIS));
		friendList.setListData(getFriendArray());
		listPanel.add(friendList);
		listPanel.add(Box.createRigidArea(new Dimension(0,5)));
		listPanel.add(getFriend);
		getFriend.addActionListener(new getFriendPushed());
		getFriend.setAlignmentX(CENTER_ALIGNMENT);
		outerPanel.add(listPanel, BorderLayout.SOUTH);
		
	}
	
	private class getFriendPushed implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			int index = friendList.getSelectedIndex();
			try {
				URL pic = friendSelected(index);
				String name = getFriendName(index);
				friendName.setText(name);
				friendPic.setIcon(new ImageIcon(pic));
				
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
		}
		
	}
	
	private void initializeElements()
	{
		outerPanel = new JPanel();
		friendList = new JList();
		friendInfoPanel = new JPanel();
		userInfoPanel = new JPanel();	
		listPanel = new JPanel();
		friendName = new JLabel();
		friendPic = new JLabel();
		getFriend = new JButton ("Get Friend");
		
	}
	
	public JPanel getOuterPanel (){
		return outerPanel;
	}

}
