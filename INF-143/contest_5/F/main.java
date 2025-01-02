import java.awt.Polygon;
import java.awt.Point;

public class main
{
	public static void main(String[] args) 
	{
		Polygon puntos = new Polygon();

		//{5, 3}, {6, 5}, {8, 7}, {7, 9}, {3, 8}, {3, 4}
		int ini_x = 1, fin_x = 5, ini_y = 1, fin_y = 6, c = 0;

		/*puntos.addPoint(2, 1);
		puntos.addPoint(5, 4);
		puntos.addPoint(5, 6);
		puntos.addPoint(1, 4);*/

		puntos.addPoint(4, 5);
		puntos.addPoint(7, 7);
		puntos.addPoint(9, 5);
		puntos.addPoint(1, 2);
		puntos.addPoint(4, 1);
		puntos.addPoint(8, 1);

		/*
		//Point p = new Point(4, 3);
		//System.out.println(puntos.contains(p));

		int x = 3; // el x debe recorrer desde ini_x a fin_x
		int cota_sup, cota_inf;
		int low = ini_y, high = fin_y + 1, mid;
		
		while(high - low > 1)
		{
			mid = (high + low) / 2;
			Point p = new Point(x, mid);

			if(!puntos.contains(p))
				low = mid;
			else
				high = mid;
		}
		System.out.println(high);
		cota_sup = high;
		
		low = ini_y;
		high = fin_y;
		

		while(high - low > 1)
		{
			mid = (high + low) / 2;
			Point p = new Point(x, mid);

			if(puntos.contains(p))
				low = mid;
			else
				high = mid;
		}
		System.out.println(low);
		cota_inf = low;
		
		//System.out.println(cota_sup + " " + cota_inf);
		//System.out.println(Math.abs(cota_inf - cota_sup));

		Point p = new Point(3, 5);
		System.out.println(puntos.contains(p));
		*/
		Point p = new Point(6, 1);
		System.out.println(puntos.contains(p));
	}
}