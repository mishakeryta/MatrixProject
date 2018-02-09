using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MatrixProject
{
    class InappropriateMatrixSizeException : Exception
    {
        public InappropriateMatrixSizeException() : base("Attempt to operate with matrix witch have different size.") { }
        public InappropriateMatrixSizeException(String message) : base(message) { }
        public InappropriateMatrixSizeException(String message,Exception inner) : base(message, inner) { }
        public InappropriateMatrixSizeException(System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
        public override string ToString()
        {
            return this.Message;
        }
    }
}
