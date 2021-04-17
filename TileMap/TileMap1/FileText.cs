using System.IO;

namespace TeacherAndStudentManagement
{
    public class FileText : File
    {
        public override int CountAmountData(string sPath)
        {
            int iCount = 0;
            string s;

            using (StreamReader sr = new StreamReader(sPath))
            {
                while ((s = sr.ReadLine()) != null)
                {
                    iCount++;
                }
            }

            return iCount;
        }

        public override string[] ReadData(string sPath)
        {
            string[] arrData = new string[CountAmountData(sPath)];
            int iIndex = 0;
            string s;

            using (StreamReader sr  = new StreamReader(sPath))
            {
                while ((s = sr.ReadLine()) != null)
                {
                    arrData[iIndex++] = s;
                }
            }

            return arrData;
        }

        public override void WriteData(string[] arrData, string sPath)
        {
            using (StreamWriter sw = new StreamWriter(sPath))
            {
                for (int i = 0; i < arrData.Length; i++)
                {
                    sw.WriteLine(arrData[i]);
                }
            }
        }
    }
}
