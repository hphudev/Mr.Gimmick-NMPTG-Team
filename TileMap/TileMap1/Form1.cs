using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using TeacherAndStudentManagement;
using XnaFan.ImageComparison;
using System.Drawing.Imaging;

namespace TileMap1
{
    public partial class Form1 : Form
    {
        private Bitmap background, tileset;

        public Form1()
        {
            InitializeComponent();
            this.StartPosition = FormStartPosition.CenterScreen;
            MakeTilemap(@"Map\Level_1");
        }

        public void MakeDirectoryPath(int i, int step, ref int max, ref int min, 
            ref string directoryName, string rootDirectoryName)
        {
            if (i % step == 0 && i != min)
            {
                max += step;
                min += step;
            }

            if (i % max >= min)
            {
                directoryName = directoryName + (i / step + 1) + "_" + rootDirectoryName + "_" +
                    i / step * step + "-" + (i / step * step + step - 1) + @"\";
            }

        }

        public List<string> GetAllDirectoryPath(int numberOfTiles, int numberOfTilesInOneRowx10, 
            string rootDirectoryName)
        {
            List<string> result = new List<string>();
            int step = numberOfTilesInOneRowx10, max = step, min = 0, max1 = max / 10, min1 = 0, 
                step1 = step / 10;
            string directoryName;

            for (int i = 0; i < numberOfTiles; i += step1)
            {
                directoryName = rootDirectoryName + @"\";
                MakeDirectoryPath(i, step, ref max, ref min, ref directoryName, rootDirectoryName);
                MakeDirectoryPath(i, step1, ref max1, ref min1, ref directoryName, rootDirectoryName);
                result.Add(directoryName);
            }

            return result;
        }

        public void CreateDirectory(int numberOfTiles, int numberOfTilesInOneRowx10, 
            string rootDirectoryName, string nameOfLevel)
        {
            List<string> allDirectoryPath = GetAllDirectoryPath(numberOfTiles, numberOfTilesInOneRowx10,
                rootDirectoryName);
            string directoryFullPath;

            foreach (string directoryPath in allDirectoryPath)
            {
                directoryFullPath = nameOfLevel + @"\" + directoryPath;
                System.IO.Directory.CreateDirectory(directoryFullPath);
            }
        }

        public int GetDimension(int arg, int tileSize)
        {
            int result = arg / tileSize, remainder = arg % tileSize;

            while (remainder <= result)
            {
                result--;
                remainder += tileSize;
            }

            return result;
        }

        public int GetRow(int height, int tileSize)
        {
            return GetDimension(height, tileSize);
        }

        public int GetColumn(int width, int tileSize)
        {
            return GetDimension(width, tileSize);
        }

        public Bitmap[] GetTileOfTileset(string name, int tileSize)
        {
            this.tileset = new Bitmap(name);
            int row = GetRow(this.tileset.Height, tileSize);
            int column = GetColumn(this.tileset.Width, tileSize);

            Bitmap[] tileOfTileset = new Bitmap[row * column];

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    Rectangle cloneRectangle = new Rectangle(j + 1 + j * tileSize, i + 1 + i * tileSize,
                        tileSize, tileSize);
                    tileOfTileset[i * column + j] = this.tileset.Clone(cloneRectangle, this.tileset.PixelFormat);
                }
            }

            return tileOfTileset;
        }

        public Bitmap[] GetTileOfBackGround(string name, int tileSize, bool isBackground = true)
        {
            this.background = new Bitmap(name);
            int row = this.background.Height / tileSize;
            int column = this.background.Width / tileSize;

            if (!isBackground)
            {
                column--;
            }

            Bitmap[] tileOfBackground = new Bitmap[row * column];

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    Rectangle cloneRectangle = new Rectangle(j * tileSize, i * tileSize, tileSize, 
                        tileSize);
                    tileOfBackground[i * column + j] = this.background.Clone(cloneRectangle, 
                        this.background.PixelFormat);
                }
            }

            return tileOfBackground;
        }

        public void SaveTile(Bitmap[] tiles, int numberOfTilesInOneRowx10, string rootDirectoryName,
            string nameOfLevel)
        {
            int length = tiles.Length, numberOfTilesInOneRow = numberOfTilesInOneRowx10 / 10;
            string[] allDirectoryPath = GetAllDirectoryPath(length, numberOfTilesInOneRowx10,
                rootDirectoryName).ToArray();
            string filePath, directoryPath = "";

            CreateDirectory(length, numberOfTilesInOneRowx10, rootDirectoryName, nameOfLevel);

            for (int i = 0; i < length; i++)
            {
                if (i % numberOfTilesInOneRow == 0)
                {
                    directoryPath = allDirectoryPath[i / numberOfTilesInOneRow];
                }

                filePath = nameOfLevel + @"\" + directoryPath + rootDirectoryName + "_" + i + ".jpg";
                tiles[i].Save(filePath, ImageFormat.Jpeg);
            }
        }

        public void SetTile(int firstIndex, int lastIndex, ref Bitmap[] tiles)
        {
            for (int i = firstIndex; i <= lastIndex; i++)
            {
                tiles[i] = new Bitmap(@"Map\Level_1\Tileset_extra\Tileset_" + i + ".jpg");
            }
        }

        public void MakeTilemap(string nameOfLevel)
        {
            FileText file = new FileText();
            string[] data = new string[1];
            string[] data1 = new string[1];
            data[0] = data1[0] = "";

            Bitmap[] tileOfTileset = GetTileOfTileset(nameOfLevel + @"\Tileset\Tileset.png", 16);
                //GetTileOfBackGround(nameOfLevel + @"\Tileset\Tileset.png", 16, false);
            int lengthOfTileSet = tileOfTileset.Length;
            Bitmap[] tilesOfBackground = GetTileOfBackGround(nameOfLevel + @"\Background\Background.png",
                16);
            int lengthOfBackGround = tilesOfBackground.Length;

            string filename = nameOfLevel + @"\Tilemap";
            int error = 0, row = 1, numberOfTilesInOneRowOfBackground = this.background.Width / 16;
            
            SaveTile(tileOfTileset, GetColumn(this.tileset.Width, 16) * 10, "Tileset", nameOfLevel);
                //numberOfTilesInOneRowOfBackground * 10, "Tileset", nameOfLevel);
            SaveTile(tilesOfBackground, numberOfTilesInOneRowOfBackground * 10, "Background", 
                nameOfLevel);

            //SetTile(320, 321, ref tileOfTileset);
            //SetTile(313, 318, ref tileOfTileset);

            for (int i = numberOfTilesInOneRowOfBackground * (row - 1); i < lengthOfBackGround; i++)
            {
                for (int j = lengthOfTileSet - 1; j >= 0; j--)
                {
                    //if (i == 3 * 130 + 2 && j == 313)
                    //{
                    //    this.pictureBox1.Image = tileOfTileset[j];
                    //    this.pictureBox2.Image = tilesOfBackground[i];
                    //    return;
                    //}

                    if (tilesOfBackground[i].PercentageDifference(tileOfTileset[j]) == 0)
                    {
                        data[0] = data[0] + j + " ";
                        data1[0] = data1[0] + j + " ";
                        break;
                    }
                    else if (j == 0)
                    {
                        data[0] = data[0] + "aaa ";
                        data1[0] = data1[0] + "aaa ";
                        error++;
                    }
                }

                if (i % ((numberOfTilesInOneRowOfBackground - 1) * row + row - 1) == 0 && i != 0)
                {
                    data1[0] += "\n";

                    if (i / (numberOfTilesInOneRowOfBackground - 1) >= 0)
                    {
                        data[0] = data[0] + "\n" + error;
                        file.WriteData(data, filename + i / (numberOfTilesInOneRowOfBackground - 1) + 
                            ".txt");
                        data[0] = "";
                        error = 0;
                    }

                    row++;
                }
            }

            file.WriteData(data1, filename + ".txt");
        }
    }
}