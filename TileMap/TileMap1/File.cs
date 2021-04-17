namespace TeacherAndStudentManagement
{
    public abstract class File
    {
        public abstract int CountAmountData(string sPath);

        public abstract string[] ReadData(string sPath);

        public abstract void WriteData(string[] arrData, string sPath);
    }
}
