using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client_side
{
    class Client
    {
        private static Client _instance;

        public static Client GetInstance()
        {
            if (_instance == null)
                _instance = new Client();
            return _instance;
        }

        private Client()
        { 
        }

        public void Connect()
        {

        }

        public void Send()
        {

        }

        public void Close()
        {
            
        }
    }
}
