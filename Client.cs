using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Client_side
{
	class Client
	{
		private static Client _instance;

		public TcpClient _tcpClient;
		public NetworkStream _networkStream;

		public static Client GetInstance()
		{
			if (_instance == null)
				_instance = new Client();
			return _instance;
		}

		private Client()
		{ 
		}

		/// <summary>
		/// 
		/// </summary>
		public void Connect(string _ip, int _port)
		{
			// start connection on ip_port
			_tcpClient = new TcpClient(_ip, _port);
			Console.WriteLine("Starting client...");
			_networkStream = _tcpClient.GetStream();
		}

		/// <summary>
		/// Send command to server
		/// </summary>
		/// <param name="_command"></param>
		/// <param name="_value"></param>
		public void Send(string _command, string _value)
		{
			// convert input from console to byte array
			byte[] bytesToSend = ASCIIEncoding.ASCII.GetBytes(_command + ";" + _value); 

			try
			{
				// try to send data to server (if failed exit program)
				_networkStream.Write(bytesToSend, 0, bytesToSend.Length); 
			}
			catch (Exception)
			{
				return;
			}
		}

		/// <summary>
		/// Close client
		/// </summary>
		public void Close()
		{
			_tcpClient.Close();
		}
	}
}
