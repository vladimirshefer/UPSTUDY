import java.util.*;
public class CarSim {

    public static void main(String args[]) {
        /*
        names[] ---> holds the first name of each driver input
        Make sure at least 3 racers.
        */

        if(args.length < 4) {
            System.out.println("Make sure to enter at least 3 racer names and then 'Stop'");
            System.exit(0);
        }
        String[] names =  new String[args.length-1];
        int index = 0;

        //Take in names to an array. Stop when "stop" is found
        while(index < args.length-1) {
            names[index] = args[index];
            index ++;
        }
        //peform race
        race(names);
    }
    //take in a string of names and randomise there times, sort and output top 3.
    public static void race(String[] names) {
        Random r = new Random();
        int minutes;
        int seconds;
        int i = 0;

        double[] time = new double[names.length];
        for(String name : names) {
            minutes = 0;
            seconds = 0;
            minutes = r.nextInt(5) + 35;
            seconds = r.nextInt(59);
            time[i] = (minutes + (seconds/100.0));

            System.out.println(name + " Finished in: " + time[i] + "!");
            double key = time[i];
            int j = i-1;
            while (j >= 0 && time[j] > key){
                time[j+1] = time[j];
                names[j+1] = names[j];
                j = j-1;
            }
            time[j+1] = key;
            names[j+1] = name;
            i++;
        }
        System.out.println("\nAND IN ORDER : \n");
        for(int k = 0; k < 3; k++){
            //System.out.println(names[k] + " has finished in: " + time[k]);
            if(k == 0) {
                System.out.println("In first place with a time of : " + time[k] + " , " + names[k]);
            }

            if(k == 1) {
                System.out.println("In second place with a time of : " + time[k] + " , " + names[k]);
            }

            if(k == 2) {
                System.out.println("In third place with a time of : " + time[k] + " , " + names[k]);
            }
        }
    }


}
