using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


namespace Client_side
{
	class SpeechRec
	{
		public SpeechRec()
		{
		}

		static void ExecProcess()
		{
			// 1) Create process info
			var psi = new ProcessStartInfo();
			psi.FileName = @"C:\Users\jhdeg\AppData\Local\Programs\Python\Python38-32\python.exe";

			// 2) Provide script and arguments
			var script = @".\backup2.py";

			// 3) Process configuration
			psi.UseShellExecute = false;
			psi.CreateNoWindow = true;
			psi.RedirectStandardOutput = true;
			psi.RedirectStandardError = true;

			// 4) Execute process and get output
			var errors = "";
			var results = "";

			using (var process = Process.Start(psi))
			{
				errors = process.StandardError.ReadToEnd();
				results = process.StandardOutput.ReadToEnd();
			}

			// 5) Display output
			Console.WriteLine("Errors:");
			Console.WriteLine(errors);
			Console.WriteLine();
			Console.WriteLine("Results:");
			Console.WriteLine(results);

		}
	}
}