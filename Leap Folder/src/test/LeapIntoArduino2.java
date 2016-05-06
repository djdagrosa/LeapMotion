package test;

import gnu.io.CommPortIdentifier; //RXTX
import gnu.io.CommPort;
import gnu.io.SerialPort;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import com.leapmotion.leap.Controller;
import com.leapmotion.leap.Frame;
import com.leapmotion.leap.Hand;
import com.leapmotion.leap.HandList;
import com.leapmotion.leap.Listener;
import com.leapmotion.leap.Vector;

class SampleListenerMain2 extends Listener {

	public void onInit(Controller controller) {
		System.out.println("Initialized");
	}

	public void onConnect(Controller controller) {
		System.out.println("Connected");
	}

	public void onDisconnect(Controller controller) {
		System.out.println("Disconnected");
	}

	public void onExit(Controller controller) {
		System.out.println("Exited");
	}

	public void onFrame(Controller controller) {
		Frame frame = controller.frame();
		HandList hands = frame.hands();
		Hand firstHand = hands.get(0);
		Vector handCenter = firstHand.palmPosition();

		double direction = handCenter.get(0);
		if (direction>180){
			direction = 10;
		}
		else if (direction<-150){
			direction=-10;
		}
		else {
			direction=0;
		}

		//Determine which hand is right
		double Speed = firstHand.direction().pitch();
		Speed = Speed*-2.5+0.5;
		Speed = Math.round(Speed);
		if (Speed==-7){
			Speed=-100;
		}	
		//System.out.println(Speed);
		LeapIntoArduino2.writeToArduino(Speed,direction);

		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class LeapIntoArduino2 {
	static DataOutputStream dOut = null;

	public static void main(String[] args) {
		// Connect to Arduino
		try {
			(new LeapIntoArduino2()).connect("COM5");
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}

		// Create a sample listener and controller
		SampleListenerMain2 listener = new SampleListenerMain2();
		Controller controller = new Controller();
		// Have the sample listener receive events from the controller
		controller.addListener(listener);
		// Keep this process running until Enter is pressed
		System.out.println("Press Enter to quit...");

		try {
			System.in.read();
		} catch (IOException e) {
			e.printStackTrace();
		}

		// Remove the sample listener when done
		controller.removeListener(listener);
	}


	void connect(String portName) throws Exception {
		System.out.println("Connecting..");
		SerialComm s = new SerialComm();
		try {
			s.connect(portName);
		}	catch (Exception e) {
			e.printStackTrace();
		}

		OutputStream out = s.getOutputStream();
		dOut = new DataOutputStream(out);
	}

	public static void writeToArduino(double speed,double direction){
		if(speed==-100){
			System.out.println("No hand detected");
		}
		//Go backwards
		if(speed==-2){
			try {
				System.out.println("Backwards");
				dOut.write('Z');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}
		
		//Go straight

		if(speed==0 && direction==0){
			try {
				System.out.println("Speed = "+ speed);	
				dOut.write('1');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		if(speed==1 && direction==0){
			try {
				System.out.println("Speed = "+ speed);
				dOut.write('2');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		if(speed==2 && direction==0){
			try {
				System.out.println("Speed = "+ speed);
				dOut.write('3');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}
		if(speed==3 && direction==0){
			try {
				System.out.println("Speed = "+ speed);
				dOut.write('4');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}

		//Turn Left
		if(speed==0 && direction==10){
			try {
				System.out.println("Turning left with speed = "+ speed);
				dOut.write('A');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		if(speed==1 && direction==10){
			try {
				System.out.println("Turning left with speed = "+ speed);
				dOut.write('B');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}
		if(speed==2 && direction==10){
			try {
				System.out.println("Turning left with speed = "+ speed);
				dOut.write('C');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		if(speed==3 && direction==10){
			try {
				System.out.println("Turning left with speed = "+ speed);
				dOut.write('D');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}


		//Turn Right
		if(speed==0 && direction==-10){
			try {
				System.out.println("Turning right with speed = "+ speed);
				dOut.write('E');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		if(speed==1 && direction==-10){
			try {
				System.out.println("Turning right with speed = "+ speed);
				dOut.write('F');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
		if(speed==2 && direction==-10){
			try {
				System.out.println("Turning right with speed = "+ speed);
				dOut.write('G');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}
		if(speed==3 && direction==-10){
			try {
				System.out.println("Turning right with speed = "+ speed);
				dOut.write('H');
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
				
		}
	}

}