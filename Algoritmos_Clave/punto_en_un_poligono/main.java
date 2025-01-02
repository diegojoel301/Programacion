import java.awt.Polygon;
import java.awt.Point;

public class main
{
	public static void main(String[] args) 
	{
		Polygon puntos = new Polygon();

		int i, j, k;
		//{5, 3}, {6, 5}, {8, 7}, {7, 9}, {3, 8}, {3, 4}
		puntos.addPoint(5, 3);
		puntos.addPoint(6, 5);
		puntos.addPoint(8, 7);
		puntos.addPoint(7, 9);
		puntos.addPoint(3, 8);
		puntos.addPoint(3, 4);

		Point p = new Point(4, 3);

		System.out.println(puntos.contains(p));

	}
}