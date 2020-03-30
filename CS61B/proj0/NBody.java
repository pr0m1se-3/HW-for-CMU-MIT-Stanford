public class NBody {

    public static double readRadius(String filename) {
        In in = new In(filename);
        int num = in.readInt();
        double r = in.readDouble();
        return r;
    }

    public static Body[] readBodies(String filename)
    {
        In in = new In(filename);
        if(in==null)
        {
            System.out.println("Fail to oprn the file!");
            return null;
        }
        int num=in.readInt();
        in.readDouble();
        Body[] Planets = new Body[num];
        for (int i=0;i<num;++i)
        {
            double xP = in.readDouble();
            double yP = in.readDouble();
            double xV = in.readDouble();
            double yV = in.readDouble();
            double m = in.readDouble();
            String img = in.readString();
            Planets[i] = new Body(xP, yP, xV, yV, m, img);
        }
        return Planets;
    }
    public static void main(String[] args) {
        double T = Double.parseDouble(args[0]);
        double dt = Double.parseDouble(args[1]);
        String fileName = args[2];
        double uniRadius = NBody.readRadius(fileName);
        Body[] Planets = NBody.readBodies(fileName);

        /** 
         * Draw the background 
         */
        StdDraw.setScale(-uniRadius, uniRadius);
        StdDraw.clear();
        StdDraw.picture(0, 0, "images/starfield.jpg");

        for (Body planet : Planets) {
            planet.draw();
        }
        
    }

}