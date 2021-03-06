﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//It is matrix class
namespace MatrixProject
{
    class Matrix
    {
        private double[,] element = null;
        private int Rows { get; set; }
        private int Cols { get; set; }
        public double this[int row, int col]
        {
            //i dont know ,if i skeep this try and catch there will it be awalible to program catch  
            get
            {
                try
                {
                    return this.element[row, col];
                }
                catch (IndexOutOfRangeException)
                {
                    throw;
                }
                catch
                {
                    throw;
                }
            }
            set
            {
                try
                {
                    this.element[row, col] = value;
                }
                catch (IndexOutOfRangeException)
                {
                    throw;
                }
            }
        }
        public Matrix(int rows = 1, int cols = 1)
        {
            try
            {
                this.element = new double[rows, cols];
            }
            catch (Exception exceptionObject)
            {
                //i dont know name of exceptions Need to be fixed.
                Console.WriteLine(exceptionObject.Message);
            }
            this.Rows = rows;
            this.Cols = cols;
        }
        public Matrix(int rows, int cols, params double[] elements)
        {
            if (rows <= 0 || cols <= 0)
            {
                throw new ArgumentException("Matrix cant have 0 rows or(and) cols.");
            }
            try
            {
                this.element = new double[rows, cols];
                for (int i = 0; i < elements.Length; ++i)
                {
                    this.element[i / cols, i % cols] = elements[i];
                }
            }
            catch
            {
                throw;
            }
            this.Rows = rows;
            this.Cols = cols;
        }
        public Matrix(Matrix matrix)
        {

            this.element = new double[matrix.Rows, matrix.Cols];
            for (int i = 0; i < matrix.Rows; ++i)
            {
                for (int j = 0; j < matrix.Cols; ++j)
                {
                    this.element[i, j] = matrix[i, j];
                }
            }
            this.Rows = matrix.Rows;
            this.Cols = matrix.Cols;
        }
        public override string ToString()
        {
            string strMatrix = "";
            for (int i = 0; i < this.Rows; ++i)
            {
                for (int j = 0; j < this.Cols; ++j)
                {
                    strMatrix += this.element[i, j].ToString() + " ";
                }
                strMatrix += "\n";
            }
            return strMatrix;
        }
        static public Matrix operator +(Matrix matrix1, Matrix matrix2)
        {
            try
            {
                Matrix resultMatrix = null;
                if (!IsAppropriateSize(matrix1,matrix2))
                {
                    throw new InappropriateMatrixSizeException();
                }
                resultMatrix = new Matrix(matrix1);
                for (int i = 0; i < matrix1.Rows; ++i)

                {
                    for (int j = 0; j < matrix1.Cols; ++j)
                    {
                        resultMatrix[i, j] += matrix2[i, j];
                    }
                }
                return resultMatrix;

            }
            catch
            {
                throw;
            }
        }
        static public Matrix operator +(Matrix matrix)
        {
            return new Matrix(matrix);
        }
        static public Matrix operator -(Matrix matrix1, Matrix matrix2)
        {
            try
            {
                if (!IsAppropriateSize(matrix1,matrix2))
                {
                    throw new InappropriateMatrixSizeException();
                }
                Matrix resultMatrix = new Matrix(matrix1.Rows,matrix1.Cols);
                for(int i = 0;i<matrix1.Rows;++i)
                {
                    for(int j = 0;j<matrix1.Cols;++j)
                    {
                        resultMatrix[i, j] = matrix1[i, j] - matrix2[i, j]; 
                    }
                }
                return resultMatrix;
            }
            catch
            {
                throw;
            }
        }
        static public Matrix operator -(Matrix matrix)
        {
            try
            {
                Matrix resultMatrix = new Matrix(matrix.Rows, matrix.Cols);
                for (int i = 0; i < resultMatrix.Rows; ++i)
                {
                    for (int j = 0; j < resultMatrix.Cols; ++j)
                    {
                        resultMatrix[i, j] = -matrix[i, j];
                    }
                }
                return resultMatrix;
            }
            catch
            {
                throw;
            }
        }
        static public Matrix operator *(Matrix matrix1,Matrix matrix2)
        {
            try
            {
                if(matrix1.Cols != matrix2.Rows)
                {
                    throw new InappropriateMatrixSizeException("You cant multiplex matrix with diferent cols adn rows(It is Beta meessge)");
                }
                
            }
        }

        static public bool IsAppropriateSize(Matrix matrix1, Matrix matrix2)
        {
            if (matrix1.Cols != matrix2.Cols || matrix1.Rows != matrix2.Rows)
            {
                return false;
            }
            return true;

        }
    }

}
