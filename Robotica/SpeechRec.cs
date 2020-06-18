using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.IO;


namespace Client_side
{
    /// <summary>
    /// De Class voor alles wat Speech Recognition doet.
    /// </summary>
    class SpeechRec
    {
        public SpeechRec()
        {

        }
        /// <summary>
        /// De functie die word aangeroepen als er op Spraak word gedrukt in de controller.
        /// Om de Python code te laten werken zijn er twee libraries nodig, deze zijn te downloaden via twee PIP commando's 
        /// <c>pip install speechrecognition</c> en <c>pip install PyAudio</c>
        /// </summary>
        public static void ExecProcess()
        {
            // 1) Het aanmaken van het proces en de interpreter klaar zetten om code uit te kunnen voeren binnen C#.
            var psi = new ProcessStartInfo();
            //Door middel van de Path.Combine en de specialfolder environment, kan er een deel van het pad naar de python.exe (interpreter) worden weggenomen. 
            // Hierdoor kan het gemakkelijker door andere mensen gebruikt worden. Aangezien vanuit die folders het pad hetzelfde is.
            psi.FileName = Path.Combine(Environment.GetFolderPath(
            Environment.SpecialFolder.ApplicationData), @"..\Local\Programs\Python\Python38\python.exe");

            // 2) Aanlevering van het uit te voeren stuk python code.
            // Script locatie kan gevonden worden binnen de Solution Explorer en daarvandaan kan het full path binnen de  "" gekopieerd worden.

            var script = @"Z:\ICT\Robotica\GitHub\Robotica\Robotica\backup2.py";
            
            psi.Arguments = $"\"{script}";

            // 3) Optie calibratie
            // Hier worden een paar opties goed gezet, zodat de output en error meldingen er goed uitkomen.
            psi.UseShellExecute = false;
            psi.CreateNoWindow = true;
            psi.RedirectStandardOutput = true;
            psi.RedirectStandardError = true;

            // 4) Voert de python code uit en slaat ze op in de desbetreffende variabelen.
            var errors = "";
            var results = "";

            //Hier word het proces gestart om de python code te runnen en worden ze in de variabelen opgeslagen.
            using (var process = Process.Start(psi))
            {
                errors = process.StandardError.ReadToEnd();
                results = process.StandardOutput.ReadToEnd();
            }

            // 5) Stuurt commando's naar de Robot en verwerkt ze.
            
            string givenCommand = results;
            string preppedCommand;
            preppedCommand = givenCommand.Replace("\r\n", String.Empty);
            preppedCommand = givenCommand.ToLower();
            
            
            if (preppedCommand == "drive forward\r\n")
            {
                Client.GetInstance().Send("RF", "10");
            }

            else if (preppedCommand == "turn left\r\n")
            {
                Client.GetInstance().Send("RO", "5");
            }

            else if (preppedCommand == "turn right\r\n")
            {
                Client.GetInstance().Send("RO", "-5");
            }

            else if (preppedCommand == "drive backwards\r\n")
            {
                Client.GetInstance().Send("RB", "10");
            }

        }
    }
}