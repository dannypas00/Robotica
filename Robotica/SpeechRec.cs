using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.IO;


namespace Client_side
{
    class SpeechRec
    {
        public SpeechRec()
        {

        }
         //TODO: Verwijder nutteloze code. Console.Writelines en script2/3
        public static void ExecProcess()
        {
            // 1) Create process info
            var psi = new ProcessStartInfo();
            psi.FileName = Path.Combine(Environment.GetFolderPath(
            Environment.SpecialFolder.ApplicationData), @"..\Local\Programs\Python\Python38\python.exe");

            // 2) Provide script and arguments
            // script locatie kan via de Solution explorer gevonden worden door op backup2.py te klikken en dan het full path
            // dat daar staat erin te slaan.

            var script = @"Z:\ICT\Robotica\GitHub\Robotica\Robotica\backup2.py";
            string path = @".'\backup.py";
            var script2 = Path.Combine(Environment.CurrentDirectory) + @"\backup.py";
            var script3 = Path.GetFullPath(path);

            psi.Arguments = $"\"{script}";

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
            //Console.WriteLine("Errors:");
            //Console.WriteLine(errors);
            //Console.WriteLine();
            //Console.WriteLine("Results:");
            Console.WriteLine(results);


            string givenCommand = results;
            string preppedCommand;
            preppedCommand = givenCommand.Replace("\r\n", String.Empty);
            preppedCommand = givenCommand.ToLower();
            Console.WriteLine(preppedCommand);
            if (preppedCommand == "drive forward\r\n")
            {
                Client.GetInstance().Send("RF", "10");
                Console.WriteLine("Driving forward");
            }

            else if (preppedCommand == "turn left\r\n")
            {
                Client.GetInstance().Send("RO", "5");
                Console.WriteLine("Turning left");
            }

            else if (preppedCommand == "turn right\r\n")
            {
                Client.GetInstance().Send("RO", "-5");
                Console.WriteLine("Turning right");
            }

            else if (preppedCommand == "drive backwards\r\n")
            {
                Client.GetInstance().Send("RB", "10");
                Console.WriteLine("Gelukt, achteruit.");
            }


            // 6) Saving commands to a text file
            //string givenCommands = @"Z:\ICT\GivenCommands.txt";
            //TextWriter tw = new StreamWriter(givenCommands, true);
            //tw.WriteLine(results);
            //tw.Close();
            //Console.ReadKey();
        }
    }
}