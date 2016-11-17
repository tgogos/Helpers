influxDB
========

add data with javascript
------------------------


```js
// pushes a random value every sec
setInterval(function(){ pushToInfluxDB()},1000);

	
	function pushToInfluxDB() {
		var load = Math.random();
		$.ajax({
		        type: 'POST',
		        url:  'http://localhost:8086/write?db=my_test_db',
		        dataType:'text',
		        data: "cpu_load_short,host=server01,region=us-west value="+load,
		        success: function(data)
		        {        
		           console.log(data)
		        },
		        error: function(err)
		        {
		          console.log(err);
		        }
		    }); 
		
	}

```
