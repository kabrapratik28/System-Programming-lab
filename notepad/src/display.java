import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.ScrollPaneConstants;


public class display {

	/**
	 * @param args
	 */
	String Text_str ; 
	public display(){
		
		JFrame frame_file = new JFrame("Notepad");
		frame_file.setSize(1000, 400);
		frame_file.setLayout(new BorderLayout());
		final JTextArea workingarea = new JTextArea() ; 
		
		JScrollPane scroll = new JScrollPane(workingarea);
		scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		
		
		JMenuBar menuBar = new JMenuBar();
		JMenu fileMenu = new JMenu("File");
		JMenu editMenu = new JMenu("Edit");
		JMenu viewMenu = new JMenu("View");
		JMenu color = new JMenu("Color");
		JMenu font = new JMenu("Font") ; 
		
		menuBar.add(fileMenu);
		menuBar.add(editMenu);
		menuBar.add(viewMenu);
		JMenuItem New = new JMenuItem("New");
		JMenuItem Open = new JMenuItem("Open");
		JMenuItem Save = new JMenuItem("Save");
		JMenuItem Saveas = new JMenuItem("Saveas");
		JMenuItem Exit = new JMenuItem("Exit");
		JMenuItem Cut = new JMenuItem("Cut");
		JMenuItem Copy = new JMenuItem("Copy");
		JMenuItem Paste = new JMenuItem("Paste");
		
		JMenuItem blue = new JMenuItem("Blue");
		JMenuItem red = new JMenuItem("Red");
		JMenuItem gray = new JMenuItem("Gray");
		JMenuItem black = new JMenuItem("Black");
		color.add(blue);
		color.add(red);
		color.add(gray);
		color.add(black);
		

		JMenuItem sansserif = new JMenuItem("SansSerif");
		JMenuItem serif = new JMenuItem("Serif");

		font.add(sansserif);
		font.add(serif);

		
		fileMenu.add(New);
		fileMenu.add(Open);
		fileMenu.addSeparator();
		fileMenu.add(Save);
		fileMenu.add(Saveas);
		fileMenu.addSeparator();
		fileMenu.add(Exit);
		editMenu.add(Cut);
		editMenu.add(Copy);
		editMenu.add(Paste);
		editMenu.addSeparator();
		viewMenu.add(color);
		viewMenu.add(font);
		JPanel menubarpanel = new JPanel();
		menubarpanel.add(menuBar);
		frame_file.add(menubarpanel, BorderLayout.NORTH);
		frame_file.add(scroll);

		
		frame_file.setVisible(true);
		
		New.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				workingarea.setText("");
			}
		});
		
		
		Open.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				JFileChooser filechoose = new JFileChooser();
				int value = filechoose.showOpenDialog(null);
				if (value == JFileChooser.APPROVE_OPTION) {
					Text_str = file_reader(filechoose.getSelectedFile().getAbsolutePath()); 
					workingarea.setText(Text_str);
					}
			}			
		});
		
		Save.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				JFileChooser fileChooser = new JFileChooser();
				if (fileChooser.showSaveDialog(null) == JFileChooser.APPROVE_OPTION) {
				  File file = fileChooser.getSelectedFile();
				  String file_saver= file.getAbsolutePath() ; 
				  file_writer(file_saver, workingarea.getText());
				}
			}
		});
		
		Saveas.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				JFileChooser fileChooser = new JFileChooser();
				if (fileChooser.showSaveDialog(null) == JFileChooser.APPROVE_OPTION) {
				  File file = fileChooser.getSelectedFile();
				  String file_saver= file.getAbsolutePath()+".exe" ; 
				  file_writer(file_saver, workingarea.getText());
				}
			}
		});
		
		Exit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
		
		Copy.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
			workingarea.copy();
			}
		});
		
		Paste.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
			workingarea.paste();
			}
		});
		
		Cut.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
			workingarea.cut();
			}
		});
		
		blue.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				workingarea.setForeground(Color.BLUE);
			
			}
		});
		
		black.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				workingarea.setForeground(Color.BLACK);
			}
		});
		
		red.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				workingarea.setForeground(Color.RED);
			}
		});
		
		gray.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				workingarea.setForeground(Color.GRAY);
			}
		});
		
		serif.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Font f = new Font("Serif", Font.PLAIN, 12);
				workingarea.setFont(f);
			}
		});
		sansserif.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Font f = new Font("Sans_serif", Font.PLAIN, 12);
				workingarea.setFont(f);
			}
		}); 
		
	}
	
	
	public String file_reader(String full_path)
	{
		String everything = "" ; 
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(full_path));
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();

	        while (line != null) {
	            sb.append(line);
	            sb.append(System.lineSeparator());
	            line = br.readLine();
	        }
	        everything = sb.toString();
	        br.close();
	    } 
		catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return everything ;
	}
	
	
	public void file_writer(String file, String contains)
	{
		Writer writer = null;

		try {
		    writer = new BufferedWriter(new OutputStreamWriter(
		          new FileOutputStream(file), "utf-8"));
		    writer.write(contains);
		} catch (Exception ex) {
		  // report
		} finally {
		   try {writer.close();} catch (Exception ex) {}
		}
		
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		display d1 = new display();
		
	}

}
