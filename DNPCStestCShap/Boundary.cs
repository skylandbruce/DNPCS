/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

namespace DNPCSformtest
{
    internal class Boundary
    {
    private
        int x_min, x_max;
        int y_min, y_max;
        int z_min, z_max;

    public Boundary(int xmin, int xmax, int ymin, int ymax, int zmin, int zmax) { 
            x_min = xmin;
            x_max = xmax;
            y_min = ymin;
            y_max = ymax;
            z_min = zmin;
            z_max = zmax;
        }

    public bool isWithinBoundary(int x, int y, int z) {
        return (x >= x_min && x <= x_max &&
                y >= y_min && y <= y_max &&
                z >= z_min && z <= z_max);
    }
        public bool isWithinBoundary(Point3D point3D)
        {
            return (point3D.X >= x_min && point3D.X <= x_max &&
                    point3D.Y >= y_min && point3D.Y <= y_max &&
                    point3D.Z >= z_min && point3D.Z <= z_max);
        }

    }
}
