public class Body {
    public double xxPos;
    public double yyPos;
    public double xxVel;
    public double yyVel;
    public double mass;
    public String imgFileName;

    public Body(double xP, double yP, double xV, double yV, double m, String img) {
        xxPos = xP;
        yyPos = yP;
        xxVel = xV;
        yyVel = yV;
        mass = m;
        imgFileName = img;
    }

    public Body(Body b) {
        xxPos = b.xxPos;
        yyPos = b.yyPos;
        xxVel = b.xxVel;
        yyVel = b.yyVel;
        mass = b.mass;
        imgFileName = b.imgFileName;
    }

    public double calcDistance(Body temp) {
        double dis = 0;
        dis = Math.pow((temp.xxPos - xxPos), 2) + Math.pow((temp.yyPos - yyPos), 2);
        dis = Math.sqrt(dis);
        return dis;
    }

    public double calcForceExertedBy(Body temp) {
        double G = 6.67e-11;
        double F = 0;
        double dis = calcDistance(temp);
        F = G * (mass * temp.mass) / Math.pow(dis, 2);
        return F;
    }

    public double calcForceExertedByX(Body temp) {
        double r = calcDistance(temp);
        double dx = temp.xxPos - xxPos;
        double F = calcForceExertedBy(temp);
        return F * dx / r;
    }

    public double calcForceExertedByY(Body temp) {
        double r = calcDistance(temp);
        double dy = temp.yyPos - yyPos;
        double F = calcForceExertedBy(temp);
        return F * dy / r;
    }

    public double calcNetForceExertedByX(Body[] allBodys) {
        double NetForcex = 0;
        for (Body body : allBodys) {
            if(this.equals(body))
                continue;
            NetForcex += calcForceExertedByX(body);
        }
        return NetForcex;
    }

    public double calcNetForceExertedByY(Body[] allBodys) {
        double NetForcey = 0;
        for (Body body : allBodys) {
            if(this.equals(body))
                continue;
            NetForcey += calcForceExertedByY(body);
        }
        return NetForcey;
    }

    public void update(double dt,double fX,double fY)
    {
        double ax=fX/mass;
        double ay=fY/mass;
        xxVel+=dt*ax;
        yyVel+=dt*ay;
        xxPos+=dt*xxVel;
        yyPos+=dt*yyVel;
    }

    public void draw()
    {
        String path="images/"+imgFileName;
        StdDraw.picture(xxPos,yyPos,path);
    }
}