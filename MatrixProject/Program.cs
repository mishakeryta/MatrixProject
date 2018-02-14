using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MatrixProject
{
    class Program
    {
        static void Main(string[] args)
        {
            MatrixProject.Matrix matrix1 = new Matrix(2, 2, 1, 1, 1, 1);
            matrix1 = -matrix1;
            Console.WriteLine(matrix1);
            Console.ReadKey(true);

        }
    }
}
