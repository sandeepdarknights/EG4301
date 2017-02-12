import webapp2
from google.appengine.ext import ndb
from read_exosite import dataCapture

data = dataCapture()
datastring = ""
for response in data:
	datastring += ",['" + str(response[0]) + "'," + str(response[1]) + "]"

html = """
		<html>
		<head>
		<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    	<script type="text/javascript">
      	google.charts.load('current', {'packages':['corechart']});
      	google.charts.setOnLoadCallback(drawChart);

      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Time', 'Patient A']
          """+ datastring + """

        ]);

        var options = {
          title: 'Temperature vs Time Plot',
          curveType: 'function',
          legend: { position: 'bottom' }
        };

        var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));

        chart.draw(data, options);
      }
    </script>
    </head>
		<body>
		<h1> Enter details </h1>
		<form action="/confirm" method="POST">

		patient: <input type="text" name="patient_name">
		<br/>
		patienttemp: <input type="text" name = "patient_temp"/>
		<input type="submit" value="Submit"/>
		</form>
		<h1>Search Patient </h1>
		<form action = "/search" method = "POST">
		patient: <input type="text" name = "patient_name">
		<br/>
		<input type="submit" value="Submit" />
		</form>
		<div id="curve_chart" style="width: 900px; height: 500px"></div>
		</body>
		</html>
		"""
print html

class Patient(ndb.Model):
	patientname = ndb.StringProperty(indexed=True)
	patienttemp = ndb.StringProperty(indexed=True)

class MainHandler(webapp2.RequestHandler):
	def get(self):
	 	self.response.out.write(html)

class MainHandlers(webapp2.RequestHandler):
	def post(self):
		name=self.request.get('patient_name')
		temp=self.request.get('patient_temp')
		patient=Patient()
		patient.patientname = name
		patient.patienttemp = temp
		patient.put()
		self.response.out.write('Details entered into the datastore')

class searchPatient(webapp2.RequestHandler):
	def post(self):
		name=self.request.get('patient_name')
		patient=Patient.query() #get all table data
		searchquery=patient.filter(Patient.patientname==name) #filter data 
		for i in searchquery: #for loop
		  self.response.write('<b>  The patient temp is %s </b>' % i.patienttemp)
		#Note: Indentation is very important, don't use tabs for the line above, use two spaces

app = webapp2.WSGIApplication([('/', MainHandler),('/confirm',MainHandlers),('/search', searchPatient)],
	debug=True)
		
