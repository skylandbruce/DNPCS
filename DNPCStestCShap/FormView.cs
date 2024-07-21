/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

using DNPCScli;

namespace DNPCSformtest
{
    public partial class FormView : Form
    {
        private readonly OStreamCLR ostreamCLR;
#if UI_ENHANCED
        private readonly Dictionary<string, Point3D> objectBuff;
        private readonly Boundary boundary;
#else
        string dataStream = "";
#endif

        public FormView()
        {
            InitializeComponent();

            ostreamCLR = new OStreamCLR();
#if UI_ENHANCED
            objectBuff = [];
            boundary = new Boundary(20,550, 20,700, 0, 37);
#endif
            ostreamCLR.DataReceived += OnDataReceived;
        }

        private void OnDataReceived(string data)
        {
            if (InvokeRequired)
            {
                Invoke(new Action<string>(OnDataReceived), data);
            }
            else
            {
#if UI_ENHANCED
                FormatObjects(data);
#else
                dataStream = data;
#endif
                this.Invalidate();
            }
        }

#if UI_ENHANCED
        private void FormatObjects(string data)
        {
            string[] pointsData = data.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries);

            foreach (string point in pointsData)
            {
                string[] parts = point.Split(':');
                if (parts.Length == 4)
                {
                    string key = parts[0];
                    int x = int.Parse(parts[1]);
                    int y = int.Parse(parts[2]);
                    int z = int.Parse(parts[3]);
                    Point3D point3D = new Point3D(x, y, z);

                    objectBuff[key] = point3D;
                }
            }
        }
#endif

        private void ButtonStart_Click(object sender, EventArgs e)
        {
            ostreamCLR.Resume();
        }

        private void ButtonStop_Click(object sender, EventArgs e)
        {
            ostreamCLR.Pause();
        }


#if UI_ENHANCED
        private void FormView_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            SolidBrush brush = (SolidBrush)Brushes.Black;
            var keysToRemove = new List<string>();

            foreach (KeyValuePair<string, Point3D> obj3D in objectBuff)
            {
                if (!boundary.isWithinBoundary(obj3D.Value))
                {
                    keysToRemove.Add(obj3D.Key);
                    continue;
                }

                if (obj3D.Key.StartsWith("Star"))
                {
                    brush = (SolidBrush)Brushes.Red;
                }
                else if (obj3D.Key.StartsWith("Rain"))
                {
                    brush = (SolidBrush)Brushes.Green;
                }
                else if (obj3D.Key.StartsWith("Snow"))
                {
                    brush = (SolidBrush)Brushes.Yellow;
                }

                g.FillEllipse(brush, obj3D.Value.X, obj3D.Value.Y, (obj3D.Value.Z+10)/2, (obj3D.Value.Z+10)/2);

            }
            foreach (var key in keysToRemove)
            {
                objectBuff.Remove(key);
            }
        }
#else
        private void FormView_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            SolidBrush brush = (SolidBrush)Brushes.Black;

            string[] pointsData = dataStream.Split(new[] { ';' }, StringSplitOptions.RemoveEmptyEntries);

            foreach (string point in pointsData)
            {
                string[] parts = point.Split(':');
                string key = "";
                int x, y, z = 0;
          
                if (parts.Length == 4)
                {
                    key = parts[0];
                    x = int.Parse(parts[1]);
                    y = int.Parse(parts[2]);
                    z = int.Parse(parts[3]);
                }
                else return;

                if (key.StartsWith("Star"))
                {
                    brush = (SolidBrush)Brushes.Red;
                }
                else if (key.StartsWith("Rain"))
                {
                    brush = (SolidBrush)Brushes.Green;
                }
                else if (key.StartsWith("Snow"))
                {
                    brush = (SolidBrush)Brushes.Yellow;
                }

                g.FillEllipse(brush, x, y, (z + 10) / 2, (z + 10) / 2);

            }
        
        }
#endif

        private void MainView_Shown(object sender, EventArgs e)
        {
            Task.Run(() => ostreamCLR.StreamThread());
        }
    }

}

