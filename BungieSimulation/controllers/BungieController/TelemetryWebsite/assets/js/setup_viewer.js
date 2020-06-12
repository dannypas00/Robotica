/* global webots: false */

var view = null;
var ipInput = null;
var portInput = null;
var connectButton = null;
var mobileDevice = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);

/*
* If mobile device, do some stuff to make it work
*/
if (mobileDevice) {
  var head = document.getElementsByTagName('head')[0];
  var jqueryTouch = document.createElement('script');
  jqueryTouch.setAttribute('type', 'text/javascript');
  jqueryTouch.setAttribute('src', 'https://www.cyberbotics.com/jquery-ui/1.11.4/jquery.ui.touch-punch.min.js');
  head.appendChild(jqueryTouch);

  var mobileCss = document.createElement('link');
  mobileCss.setAttribute('rel', 'stylesheet');
  mobileCss.setAttribute('type', 'text/css');
  mobileCss.setAttribute('href', 'https://www.cyberbotics.com/wwi/R2020a/wwi_mobile.css');
  head.appendChild(mobileCss);
}

/*
* Init the inputs and set layout for WeBots UI
*/
function init() {
  ipInput = document.getElementById('IPInput');
  portInput = document.getElementById('PortInput');
  connectButton = document.getElementById('ConnectButton');
  $('body').layout({
    center__maskContents: true,
    south__size: 128,
    north__resizable: false
  });
}

/*
* Get the playerDiv and initialize an new instance of the WeBots Streaming Service
*/
function connect() {
  var playerDiv = document.getElementById('playerDiv');
  view = new webots.View(playerDiv, mobileDevice);
  view.broadcast = true;
  view.open('ws://' + ipInput.value + ':' + portInput.value);
  connectButton.value = 'Disconnect';
  connectButton.onclick = disconnect;
  ipInput.disabled = true;
  portInput.disabled = true;

  // Hide loading divs and show content from WeBots
  $('#robot-data-status-waiting').hide();
  $('#robot-data-warnings-waiting').hide();
  $('#robot-data-status').show();
  $('#robot-data-warnings').show();

  // Subscribe to the Console/Terminal of the WeBots UI
  $('.webotsConsoleLogs').bind('DOMSubtreeModified', function(){
    // Get data and reset fields
    let data = $('.webotsConsoleLogs').contents();
    $('#robot-data-status').empty();
    $('#robot-data-warnings').empty();
    // Latest and currently running action
    let currentAction = null;
    // Based on the values form WeBots itself, we append them to the side div
    for (i = 0; i < data.length; i++) {
      let splitData = data[i].innerHTML.split(" ");

      if (splitData[1] == "[ACTION]" || splitData[1] == "[STATUS]") {
        let color = ((splitData[1] == "[ACTION]") ? 'blue' : 'green');
        $('#robot-data-status').append('<li class="list-group-item" style="color: ' + color + '">' + data[i].innerHTML + '</li>');
        if (splitData[1] == "[ACTION]") {
          currentAction = data[i].innerHTML;
        }
      } else {
        $('#robot-data-warnings').append('<li class="list-group-item">' + data[i].innerHTML + '</li>');
      }
    }

    // Done getting data, check current task
    if (currentAction != null) {
      let splitAction = currentAction.split(" ");
      splitAction.splice(splitAction[0], 2);
      $('#currentAction').html('<span style="font-weight: bold;">Last Command: </span><span style="color: blue; font-weight: bold;"> ' + splitAction.join(" ") + '</span>');
    }

  });
}

/*
* Clear all console data, hide and show certain divs
*/
function clearConsole() {
  $('#robot-data-status').empty();
  $('#robot-data-warnings').empty();
  $('#currentAction').empty();
  $('.webotsConsoleLogs').empty();
  $('#robot-data-status-waiting').show();
  $('#robot-data-warnings-waiting').show();
  $('#robot-data-status').hide();
  $('#robot-data-warnings').hide();
}

/*
* Close connection, clear all local data and make the view ready to connect again
*/
function disconnect() {
  view.close();
  view = null;
  var playerDiv = document.getElementById('playerDiv');
  playerDiv.innerHTML = null;
  connectButton.value = 'Connect';
  connectButton.onclick = connect;
  ipInput.disabled = false;
  portInput.disabled = false;
  clearConsole();
}

window.addEventListener('load', init, false);
