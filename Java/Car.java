public class Car {
    String model;
    String com;
    String driver;
    
    public Car(String com, String model, String driver) {
        this.com = com;
        this.model = model;
        this.driver = driver;
    }
    
    public void startEngine(String fuelType) {
        System.out.println(model + " driven by " + driver + " engine started with " + fuelType + " fuel.");
    }

    public static void main(String[] args){
        Car[] f1 = new Car[6];
    
        f1[0] = new Car("Mercedes","AMG F1 W11", "L.Hamilton");
        f1[1] = new Car("Ferrari", "F2004", "M.Schumacher");
        f1[2] = new Car("Red Bull","RB16B", "Max Verstapen");
        f1[3] = new Car("McLaren", "MP4/4", "Ayrton Senna");
        f1[4] = new Car("Williams", "FW14B", "Nigel Mansell");
        f1[5] = new Car("Lotus", "72", "Emerson Fittipaldi");
    
        String[] fuel = {"Hydrogen", "Diesel", "Diesel", "Petrol", "Hybrid", "Petrol"};

        // Loop through cars and start their engines
        for(int i = 0; i < f1.length; i++){
            f1[i].startEngine(fuel[i]); // Call startEngine without System.out.println
        }
    }
}