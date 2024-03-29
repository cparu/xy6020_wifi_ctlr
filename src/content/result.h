// Length 2339 / 3949
const char PROGMEM html__index[] = "<!DOCTYPE html><html><head><script type=text/javascript src=segment-display.js></script><script type=text/javascript src=logic.js></script><link rel=stylesheet type=text/css href=style.css><title>XY6020 Control</title></head><body onload=init()><center><div id=main-page><h1 style=\"font-size: 50px; color: gray\">XY6020 Control <span id=connection-state style=\"display: inline; color: lightgreen;\">&#10003;</span></h1><button class=my-button id=on-button onclick=setOutput(1)>ON</button><br><button class=\"my-button active-button\" id=off-button onclick=setOutput(0)>OFF</button><br><br><button class=my-button id=settings-button onclick=goToSettings()>Settings</button><br><br><div class=my-container><span>Actual values</span><table><tr><td class=\"segment-label description\">Voltage:</td><td> <canvas id=actVoltage width=120 height=34></canvas> </td><td class=\"segment-label unit colored-voltage\">V</td></tr><tr><td class=\"segment-label description\">Current:</td><td> <canvas id=actCurrent width=120 height=34></canvas> </td><td class=\"segment-label unit colored-current\">A</td></tr><tr><td class=\"segment-label description\">Power:</td><td> <canvas id=actPower width=120 height=34></canvas> </td><td class=\"segment-label unit colored-power\">W</td></tr><tr><td class=\"segment-label description\">Input Voltage:</td><td> <canvas id=inputVoltage width=120 height=34></canvas> </td><td class=\"segment-label unit\" style=\"color: #ffffa0\">V</td></tr></table></div><br><div class=my-container><span>Limits</span><table><tr><td class=\"segment-label description\">Voltage:</td><td> <canvas id=targetVoltage width=120 height=34></canvas> </td><td class=\"segment-label unit\">V</td><td><button class=small-button id=set-voltage-button onclick=setTargetValue(this.id)>SET</button></td></tr><tr><td class=\"segment-label description\">Current:</td><td> <canvas id=targetCurrent width=120 height=34></canvas> </td><td class=\"segment-label unit\">A</td><td><button class=small-button id=set-current-button onclick=setTargetValue(this.id)>SET</button></td></tr><tr><td class=\"segment-label description\">Power:</td><td> <canvas id=targetPower width=120 height=34></canvas> </td><td class=\"segment-label unit\">W</td><td><button class=small-button id=set-power-button onclick=setTargetValue(this.id)>SET</button></td></tr></table></div></div></center></body></html>";
// Length 2404 / 3481
const char PROGMEM css__style[] = ".my-input,.my-label{color:inherit;min-width:0}.my-input,.switch{box-sizing:border-box}.switch:after,.switch:before{content:'';position:absolute}body{background-color:#272624;color:#fff}.my-label{align-items:left;display:flex;font-weight:700;padding-bottom:.25rem;padding-top:.25rem;font-size:20px;vertical-align:middle;margin:10px}.my-input{background-color:#363f4f;border:.125rem solid transparent;border-radius:.5rem;display:block;font-family:inherit;font-size:inherit;font-weight:400;line-height:inherit;margin:3px 3px 3px 10px;outline:0;padding:.05rem .5rem;width:100%}.my-button,.my-container,.small-button,.switch{display:inline-block}.my-input:focus{border-color:#1c76fd}.switch{appearance:none;color:#1c76fd;cursor:pointer;height:1.25rem;position:relative;width:2rem}.my-button,.my-button a,.small-button{color:#fff;text-decoration:none}.switch:after{background-color:#fff;border-radius:100%;display:block;height:.875rem;left:.1875rem;top:.1875rem;transition:left .3s;width:.875rem;z-index:2}.switch:before{background-color:#363f4f;border-radius:2rem;display:block;height:100%;left:0;top:0;transition:background-color .3s;width:100%;z-index:1}.switch:checked:after{left:1rem}.switch:checked:before{background-color:currentColor}.my-button a{text-decoration-color:red}.my-container{width:50%;border:2px solid grey;border-radius:10px;margin:3px auto;padding:0 15px 15px}.my-param-table{width:100%}.my-container>span:first-child{color:#ccc;display:block;border-top-left-radius:10px;border-top-right-radius:10px;margin-bottom:30px;margin-left:-15px;margin-right:-15px;padding-left:10px;background-color:#5b5e55;text-align:left;font-weight:700;font-size:32px}.small-button:hover{background-color:#2d2f2d;font-weight:700}.small-button{background-color:#1d1f1d;border:none;border-radius:7px;padding:10px;text-align:center;font-size:15px}.my-button.small{width:320px}.my-button{width:413px;background-color:#383b38;border:none;border-radius:7px;padding:20px 120px;text-align:center;font-size:20px;font-weight:700}.my-active-button:hover{background-color:#5c665c!important}.my-button:hover{background-color:#2d2f2d}.my-active-button{background-color:#869486}.segment-label{font-size:28px;font-weight:700;position:relative;bottom:3px}.unit{font-size:40px}.description{color:gray;text-align:right;padding-right:15px}.colored-voltage{color:#a0a0ff}.colored-current{color:#ffa0a0}.colored-power{color:#a0ffa0}";
// Length 8377 / 13600
const char PROGMEM js__segmentdisplay[] = "/*!\n * segment-display.js\n *\n * Copyright 2012, RÃ¼diger Appel\n * http://www.3quarks.com\n * Published under Creative Commons 3.0 License.\n *\n * Date: 2012-02-14\n * Version: 1.0.0\n * \n * Dokumentation: http://www.3quarks.com/de/Segmentanzeige\n * Documentation: http://www.3quarks.com/en/SegmentDisplay\n */ function SegmentDisplay(t){this.displayId=t,this.pattern=\"##:##:##\",this.value=\"12:34:56\",this.digitHeight=20,this.digitWidth=10,this.digitDistance=2.5,this.displayAngle=12,this.segmentWidth=2.5,this.segmentDistance=.2,this.segmentCount=SegmentDisplay.SevenSegment,this.cornerType=SegmentDisplay.RoundedCorner,this.colorOn=\"rgb(233, 93, 15)\",this.colorOff=\"rgb(75, 30, 5)\"}SegmentDisplay.SevenSegment=7,SegmentDisplay.FourteenSegment=14,SegmentDisplay.SixteenSegment=16,SegmentDisplay.SymmetricCorner=0,SegmentDisplay.SquaredCorner=1,SegmentDisplay.RoundedCorner=2,SegmentDisplay.prototype.setValue=function(t){this.value=t,this.draw()},SegmentDisplay.prototype.draw=function(){var t=document.getElementById(this.displayId);if(t){var i=t.getContext(\"2d\");if(i){i.clearRect(0,0,t.width,t.height);var e=0,s=!0;if(this.pattern)for(var h=0;h<this.pattern.length;h++){var n=this.pattern.charAt(h).toLowerCase();if(\"#\"==n)e+=this.digitWidth;else if(\".\"==n||\":\"==n)e+=this.segmentWidth;else if(\" \"!=n)return;e+=s?0:this.digitDistance,s=!1}if(e<=0)return;var g=Math.tan(-1*Math.max(-45,Math.min(45,this.displayAngle))*Math.PI/180),d=Math.min(t.width/(e+Math.abs(g*this.digitHeight)),t.height/this.digitHeight),o=(t.width-(e+g*this.digitHeight)*d)/2,m=(t.height-this.digitHeight*d)/2;i.save(),i.translate(o,m),i.scale(d,d),i.transform(1,0,g,1,0,0);for(var r=0,l=this.value?this.value.length:0,h=0;h<this.pattern.length;h++){var a=this.pattern.charAt(h),W=h<l?this.value.charAt(h).toLowerCase():\" \";r+=this.drawDigit(i,r,a,W)}i.restore()}}},SegmentDisplay.prototype.drawDigit=function(t,i,e,s){switch(e){case\"#\":this.segmentWidth,this.segmentWidth;var h=Math.sqrt(this.segmentDistance*this.segmentDistance/2),n=h/2,g=(this.segmentWidth-h)*Math.sin(45*Math.PI/180),d=g/2,o=(this.digitHeight-3*this.segmentWidth)/2;this.digitWidth,this.segmentWidth;var m=this.segmentWidth/2;this.digitWidth;var r=i,l=0;switch(t.fillStyle=this.getSegmentColor(s,\"02356789acefp\",\"02356789abcdefgiopqrstz@\"),t.beginPath(),this.cornerType){case SegmentDisplay.SymmetricCorner:t.moveTo(r+m+h,l+m),t.lineTo(r+this.segmentWidth+h,l),t.lineTo(r+this.digitWidth-this.segmentWidth-h,l),t.lineTo(r+this.digitWidth-m-h,l+m);break;case SegmentDisplay.SquaredCorner:t.moveTo(r+m+n,l+m-n),t.lineTo(r+this.segmentWidth,l),t.lineTo(r+this.digitWidth-this.segmentWidth,l),t.lineTo(r+this.digitWidth-m-n,l+m-n);break;default:t.moveTo(r+this.segmentWidth-g,l+this.segmentWidth-g-h),t.quadraticCurveTo(r+this.segmentWidth-d,l,r+this.segmentWidth,l),t.lineTo(r+this.digitWidth-this.segmentWidth,l),t.quadraticCurveTo(r+this.digitWidth-this.segmentWidth+d,l,r+this.digitWidth-this.segmentWidth+g,l+this.segmentWidth-g-h)}switch(t.lineTo(r+this.digitWidth-this.segmentWidth-h,l+this.segmentWidth),t.lineTo(r+this.segmentWidth+h,l+this.segmentWidth),t.fill(),r=i+this.digitWidth-this.segmentWidth,l=0,t.fillStyle=this.getSegmentColor(s,\"01234789adhpy\",\"01234789abdhjmnopqruwy\"),t.beginPath(),this.cornerType){case SegmentDisplay.SymmetricCorner:t.moveTo(r+m,l+m+h),t.lineTo(r+this.segmentWidth,l+this.segmentWidth+h);break;case SegmentDisplay.SquaredCorner:t.moveTo(r+m+n,l+m+n),t.lineTo(r+this.segmentWidth,l+this.segmentWidth);break;default:t.moveTo(r+g+h,l+this.segmentWidth-g),t.quadraticCurveTo(r+this.segmentWidth,l+this.segmentWidth-d,r+this.segmentWidth,l+this.segmentWidth)}switch(t.lineTo(r+this.segmentWidth,l+o+this.segmentWidth-h),t.lineTo(r+m,l+o+this.segmentWidth+m-h),t.lineTo(r,l+o+this.segmentWidth-h),t.lineTo(r,l+this.segmentWidth+h),t.fill(),r=i+this.digitWidth-this.segmentWidth,l=o+this.segmentWidth,t.fillStyle=this.getSegmentColor(s,\"013456789abdhnouy\",\"01346789abdghjmnoqsuw@\",\"%\"),t.beginPath(),t.moveTo(r,l+this.segmentWidth+h),t.lineTo(r+m,l+m+h),t.lineTo(r+this.segmentWidth,l+this.segmentWidth+h),t.lineTo(r+this.segmentWidth,l+o+this.segmentWidth-h),this.cornerType){case SegmentDisplay.SymmetricCorner:t.lineTo(r+m,l+o+this.segmentWidth+m-h),t.lineTo(r,l+o+this.segmentWidth-h);break;case SegmentDisplay.SquaredCorner:t.lineTo(r+m+n,l+o+this.segmentWidth+m-n),t.lineTo(r,l+o+this.segmentWidth-h);break;default:t.quadraticCurveTo(r+this.segmentWidth,l+o+this.segmentWidth+d,r+g+h,l+o+this.segmentWidth+g),t.lineTo(r,l+o+this.segmentWidth-h)}switch(t.fill(),r=i,l=this.digitHeight-this.segmentWidth,t.fillStyle=this.getSegmentColor(s,\"0235689bcdelotuy_\",\"0235689bcdegijloqsuz_=@\"),t.beginPath(),t.moveTo(r+this.segmentWidth+h,l),t.lineTo(r+this.digitWidth-this.segmentWidth-h,l),this.cornerType){case SegmentDisplay.SymmetricCorner:t.lineTo(r+this.digitWidth-m-h,l+m),t.lineTo(r+this.digitWidth-this.segmentWidth-h,l+this.segmentWidth),t.lineTo(r+this.segmentWidth+h,l+this.segmentWidth),t.lineTo(r+m+h,l+m);break;case SegmentDisplay.SquaredCorner:t.lineTo(r+this.digitWidth-m-n,l+m+n),t.lineTo(r+this.digitWidth-this.segmentWidth,l+this.segmentWidth),t.lineTo(r+this.segmentWidth,l+this.segmentWidth),t.lineTo(r+m+n,l+m+n);break;default:t.lineTo(r+this.digitWidth-this.segmentWidth+g,l+g+h),t.quadraticCurveTo(r+this.digitWidth-this.segmentWidth+d,l+this.segmentWidth,r+this.digitWidth-this.segmentWidth,l+this.segmentWidth),t.lineTo(r+this.segmentWidth,l+this.segmentWidth),t.quadraticCurveTo(r+this.segmentWidth-d,l+this.segmentWidth,r+this.segmentWidth-g,l+g+h),t.lineTo(r+this.segmentWidth-g,l+g+h)}switch(t.fill(),r=i,l=o+this.segmentWidth,t.fillStyle=this.getSegmentColor(s,\"0268abcdefhlnoprtu\",\"0268acefghjklmnopqruvw@\"),t.beginPath(),t.moveTo(r,l+this.segmentWidth+h),t.lineTo(r+m,l+m+h),t.lineTo(r+this.segmentWidth,l+this.segmentWidth+h),t.lineTo(r+this.segmentWidth,l+o+this.segmentWidth-h),this.cornerType){case SegmentDisplay.SymmetricCorner:t.lineTo(r+m,l+o+this.segmentWidth+m-h),t.lineTo(r,l+o+this.segmentWidth-h);break;case SegmentDisplay.SquaredCorner:t.lineTo(r+m-n,l+o+this.segmentWidth+m-h+n),t.lineTo(r,l+o+this.segmentWidth);break;default:t.lineTo(r+this.segmentWidth-g-h,l+o+this.segmentWidth+g),t.quadraticCurveTo(r,l+o+this.segmentWidth+d,r,l+o+this.segmentWidth)}switch(t.fill(),r=i,l=0,t.fillStyle=this.getSegmentColor(s,\"045689abcefhlpty\",\"045689acefghklmnopqrsuvwy@\",\"%\"),t.beginPath(),t.moveTo(r+this.segmentWidth,l+this.segmentWidth+h),t.lineTo(r+this.segmentWidth,l+o+this.segmentWidth-h),t.lineTo(r+m,l+o+this.segmentWidth+m-h),t.lineTo(r,l+o+this.segmentWidth-h),this.cornerType){case SegmentDisplay.SymmetricCorner:t.lineTo(r,l+this.segmentWidth+h),t.lineTo(r+m,l+m+h);break;case SegmentDisplay.SquaredCorner:t.lineTo(r,l+this.segmentWidth),t.lineTo(r+m-n,l+m+n);break;default:t.lineTo(r,l+this.segmentWidth),t.quadraticCurveTo(r,l+this.segmentWidth-d,r+this.segmentWidth-g-h,l+this.segmentWidth-g),t.lineTo(r+this.segmentWidth-g-h,l+this.segmentWidth-g)}return t.fill(),7==this.segmentCount&&(r=i,l=(this.digitHeight-this.segmentWidth)/2,t.fillStyle=this.getSegmentColor(s,\"2345689abdefhnoprty-=\"),t.beginPath(),t.moveTo(r+m+h,l+m),t.lineTo(r+this.segmentWidth+h,l),t.lineTo(r+this.digitWidth-this.segmentWidth-h,l),t.lineTo(r+this.digitWidth-m-h,l+m),t.lineTo(r+this.digitWidth-this.segmentWidth-h,l+this.segmentWidth),t.lineTo(r+this.segmentWidth+h,l+this.segmentWidth),t.fill()),this.digitDistance+this.digitWidth;case\".\":return t.fillStyle=\"#\"==s||\".\"==s?this.colorOn:this.colorOff,this.drawPoint(t,i,this.digitHeight-this.segmentWidth,this.segmentWidth),this.digitDistance+this.segmentWidth;case\":\":t.fillStyle=\"#\"==s||\":\"==s?this.colorOn:this.colorOff;var l=(this.digitHeight-this.segmentWidth)/2-this.segmentWidth;return this.drawPoint(t,i,l,this.segmentWidth),this.drawPoint(t,i,l+2*this.segmentWidth,this.segmentWidth),this.digitDistance+this.segmentWidth;default:return this.digitDistance}},SegmentDisplay.prototype.drawPoint=function(t,i,e,s){var h=i+s,n=e+s,g=s/4;t.beginPath(),t.moveTo(h-g,e),t.quadraticCurveTo(h,e,h,e+g),t.lineTo(h,n-g),t.quadraticCurveTo(h,n,h-g,n),t.lineTo(i+g,n),t.quadraticCurveTo(i,n,i,n-g),t.lineTo(i,e+g),t.quadraticCurveTo(i,e,i+g,e),t.fill()},SegmentDisplay.prototype.getSegmentColor=function(t,i,e,s){return\"#\"==t?this.colorOn:7===this.segmentCount?-1==i.indexOf(t)?this.colorOff:this.colorOn:(!1,this.colorOff)};";
// Length 6234 / 9192
const char PROGMEM js__logic[] = "function init(){createSegments(),setInterval(function(){getData()},500)}function getData(){var e=new XMLHttpRequest;e.onreadystatechange=function(){if(4==this.readyState&&200==this.status){let e=JSON.parse(this.responseText);setDisplayValue(displayActVoltage,e.voltage),setDisplayValue(displayActCurrent,e.current),setDisplayValue(displayActPower,e.power),document.getElementById(\"on-button\").classList.remove(\"my-active-button\"),document.getElementById(\"off-button\").classList.remove(\"my-active-button\"),e.output?document.getElementById(\"on-button\").classList.add(\"my-active-button\"):document.getElementById(\"off-button\").classList.add(\"my-active-button\"),setDisplayValue(displayTargetVoltage,e.tvoltage),setDisplayValue(displayTargetCurrent,e.tcurrent),setDisplayValue(displayTargetPower,e.tpower),setDisplayValue(displayInputVoltage,e.ivoltage),item=document.querySelector(\"[id='connection-state']\"),e.connected?item.style.display=\"inline\":item.style.display=\"none\"}},e.open(\"GET\",server_ip+\"/control\",!0),e.send()}function getConfig(){var e=new XMLHttpRequest;e.onreadystatechange=function(){if(4==this.readyState&&200==this.status){console.log(this.responseText);let e=JSON.parse(this.responseText);console.log(e),(inp=document.querySelector(\"[name='ssid']\")).value=e.ssid,(inp=document.querySelector(\"[name='use-static-ip']\")).checked=e[\"use-static-ip\"],(inp=document.querySelector(\"[name='static-ip']\")).value=e[\"static-ip\"],(inp=document.querySelector(\"[name='subnet']\")).value=e.subnet,(inp=document.querySelector(\"[name='gateway']\")).value=e.gateway,(inp=document.querySelector(\"[name='mqtt-server']\")).value=e[\"mqtt-server\"],(inp=document.querySelector(\"[name='mqtt-port']\")).value=e[\"mqtt-port\"],(inp=document.querySelector(\"[name='mqtt-user']\")).value=e[\"mqtt-user\"],(inp=document.querySelector(\"[name='mqtt-id']\")).value=e[\"mqtt-id\"],(inp=document.querySelector(\"[name='zero-feed-in']\")).checked=e[\"zero-feed-in\"],(inp=document.querySelector(\"[name='smi-topic']\")).value=e[\"smi-topic\"],(inp=document.querySelector(\"[name='sm-name']\")).value=e[\"sm-name\"],(inp=document.querySelector(\"[name='enable-input-limits']\")).checked=e[\"enable-input-limits\"],(inp=document.querySelector(\"[name='switch-off-voltage']\")).value=e[\"switch-off-voltage\"],(inp=document.querySelector(\"[name='switch-on-voltage']\")).value=e[\"switch-on-voltage\"]}},e.open(\"GET\",server_ip+\"/config\",!0),e.send()}function applySettings(e){var t=new XMLHttpRequest;t.onreadystatechange=function(){4==this.readyState&&200==this.status&&\"OK\"!=this.responseText&&alert(\"Applying settings failed!\")},t.open(\"POST\",server_ip+\"/config\",!0),cfg={},inp=document.querySelector(\"[name='ssid']\"),cfg.ssid=inp.value,inp=document.querySelector(\"[name='wifi-pass']\"),cfg[\"wifi-password\"]=inp.value,inp=document.querySelector(\"[name='use-static-ip']\"),cfg[\"use-static-ip\"]=inp.checked,inp=document.querySelector(\"[name='static-ip']\"),cfg[\"static-ip\"]=inp.value,inp=document.querySelector(\"[name='subnet']\"),cfg.subnet=inp.value,inp=document.querySelector(\"[name='gateway']\"),cfg.gateway=inp.value,inp=document.querySelector(\"[name='mqtt-server']\"),cfg[\"mqtt-server\"]=inp.value,inp=document.querySelector(\"[name='mqtt-port']\"),cfg[\"mqtt-port\"]=parseInt(inp.value),inp=document.querySelector(\"[name='mqtt-user']\"),cfg[\"mqtt-user\"]=inp.value,inp=document.querySelector(\"[name='mqtt-pass']\"),cfg[\"mqtt-pass\"]=inp.value,inp=document.querySelector(\"[name='mqtt-id']\"),cfg[\"mqtt-id\"]=inp.value,inp=document.querySelector(\"[name='zero-feed-in']\"),cfg[\"zero-feed-in\"]=inp.checked,inp=document.querySelector(\"[name='smi-topic']\"),cfg[\"smi-topic\"]=inp.value,inp=document.querySelector(\"[name='sm-name']\"),cfg[\"sm-name\"]=inp.value,inp=document.querySelector(\"[name='enable-input-limits']\"),cfg[\"enable-input-limits\"]=inp.checked,inp=document.querySelector(\"[name='switch-off-voltage']\"),cfg[\"switch-off-voltage\"]=inp.value,inp=document.querySelector(\"[name='switch-on-voltage']\"),cfg[\"switch-on-voltage\"]=inp.value,data=JSON.stringify(cfg),console.log(data),t.send(data)}function goBack(){window.location.href=\"index.html\"}function goToSettings(){window.location.href=\"settings.html\"}function resetEsp(){var e=new XMLHttpRequest;e.open(\"POST\",server_ip+\"/control?reset\",!0),e.send(),goBack()}function setOutput(e){var t=new XMLHttpRequest;t.onreadystatechange=function(){4==this.readyState&&200==this.status&&\"OK\"!=this.responseText&&alert(\"Set output failed!\")},t.open(\"POST\",server_ip+\"/control?output=\"+e,!0),t.send()}function setTargetValue(e){if(null!=(value=prompt(\"Please enter target value...\"))&&parseFloat(value)!=NaN){var t=new XMLHttpRequest;t.onreadystatechange=function(){4==this.readyState&&200==this.status&&\"OK\"!=this.responseText&&alert(\"Set parameter failed!\")};var a=\"\";\"set-voltage-button\"==e?a=\"voltage\":\"set-current-button\"==e&&(a=\"current\"),\"set-power-button\"==e&&(a=\"max-power\"),value=parseFloat(value),t.open(\"POST\",server_ip+\"/control?\"+a+\"=\"+value,!0),t.send()}}function createSegment(e){e.pattern=\"###.##\",e.displayAngle=1.5,e.digitHeight=21,e.digitWidth=14,e.digitDistance=3.1,e.segmentWidth=2.9,e.segmentDistance=.9,e.segmentCount=7,e.cornerType=3,e.colorOn=\"#f0f0f0\",e.colorOff=\"#3b3b3b\",e.draw(),e.setValue(\"  0.00\")}function createSegments(){createSegment(displayActVoltage=new SegmentDisplay(\"actVoltage\")),displayActVoltage.colorOn=\"#a0a0ff\",createSegment(displayActCurrent=new SegmentDisplay(\"actCurrent\")),displayActCurrent.colorOn=\"#ffa0a0\",createSegment(displayActPower=new SegmentDisplay(\"actPower\")),displayActPower.colorOn=\"#a0ffa0\",displayActPower.pattern=\"####.#\",displayActPower.setValue(\"   0.0\"),createSegment(displayInputVoltage=new SegmentDisplay(\"inputVoltage\")),displayInputVoltage.colorOn=\"#ffffa0\",setDisplayValue(displayInputVoltage,0),createSegment(displayTargetVoltage=new SegmentDisplay(\"targetVoltage\")),createSegment(displayTargetCurrent=new SegmentDisplay(\"targetCurrent\")),createSegment(displayTargetPower=new SegmentDisplay(\"targetPower\")),displayTargetPower.pattern=\"####.#\",displayTargetPower.setValue(\"   0.0\")}function setDisplayValue(e,t){var a=e.pattern.split(\".\"),n=e.pattern.length,s=a[1].length,r=String(t).split(\".\"),o=\"\";2==r.length&&(o=r[1]),o=o.padEnd(s,\"0\"),e.setValue(r[0].padStart(n-s-1)+\".\"+o)}server_ip=\"\";";
// Length 3279 / 5377
const char PROGMEM html__settings[] = "<!DOCTYPE html><html><head><script type=text/javascript src=logic.js></script><link rel=stylesheet type=text/css href=style.css><title>XY6020 Settings</title></head><body onload=getConfig()><center><h1 style=\"font-size: 50px; color: gray\">XY6020 Settings</h1><div id=settings-page><div class=my-container><span>WiFi</span><table class=my-param-table><tr><td><span class=my-label>SSID:</span></td><td style=\"width: 70%\"><input type=text class=my-input name=ssid placeholder=SSID></td></tr><tr><td><span class=my-label>Password:</span></td><td><input type=password class=my-input name=wifi-pass></td></tr></table></div></div><div class=my-container><span>DHCP</span><table class=my-param-table><tr><td><span class=my-label>Use static ip address</span></td><td style=\"width: 70%\"><input type=checkbox id=use-static-ip name=use-static-ip class=switch></td></tr><tr><td><span class=my-label>IP address:</span></td><td><input type=text class=my-input name=static-ip></td></tr><tr><td><span class=my-label>Subnet mask:</span></td><td><input type=text class=my-input name=subnet></td></tr><tr><td><span class=my-label>Gateway:</span></td><td><input type=text class=my-input name=gateway></td></tr></table></div><div class=my-container><span>MQTT</span><table class=my-param-table><tr><td><span class=my-label>Server ip:</span></td><td style=\"width: 70%\"><input type=text class=my-input name=mqtt-server></td></tr><tr><td><span class=my-label>Server port:</span></td><td><input type=text class=my-input name=mqtt-port></td></tr><tr><td><span class=my-label>User:</span></td><td><input type=text class=my-input name=mqtt-user placeholder=user></td></tr><tr><td><span class=my-label>Password:</span></td><td><input type=password class=my-input name=mqtt-pass></td></tr><tr><td><span class=my-label>Client ID:</span></td><td><input type=text class=my-input name=mqtt-id placeholder=xy6020_MMMMMMMMMMMM></td></tr></table></div><div class=my-container><span>Electricity feed-in</span><table class=my-param-table><tr><td><span class=my-label>Zero feed-in mode</span></td><td style=\"width: 70%\"><input type=checkbox id=checkbox0 name=zero-feed-in class=switch></td></tr><tr><td><span class=my-label>Tasmota SMI MQTT topic:</span></td><td><input type=text class=my-input name=smi-topic></td></tr><tr><td><span class=my-label>Smart meter name:</span></td><td><input type=text class=my-input name=sm-name></td></tr></table></div><div class=my-container><span>Input voltage limits</span><table class=my-param-table><tr><td><span class=my-label>Enable limits</span></td><td style=\"width: 70%\"><input type=checkbox id=checkbox0 name=enable-input-limits class=switch></td></tr><tr><td><span class=my-label>Switch off lower voltage:</span></td><td><input type=number class=my-input name=switch-off-voltage></td></tr><tr><td><span class=my-label>Switch on over voltage:</span></td><td><input type=text class=my-input name=switch-on-voltage></td></tr></table></div><br><br><br><div style=\"width: 60%; margin:0px; padding: 0px;\"><button class=\" my-button small\" id=back-button onclick=goBack()>Back</button><button class=\" my-button small\" id=apply-button onclick=applySettings()>Apply</button><button class=\" my-button small\" id=reset-button onclick=resetEsp()>Reboot</button></div></center></body></html>";
