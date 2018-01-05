TODO make timestamp/name/metric unique key

To create the datastore resource, make a dataset with url "photos" then:
$ curl -X POST http://127.0.0.1:5000/api/3/action/datastore_create \
-H "Authorization: {YOUR-SYSADMIN-API-KEY}" \
-d '{"resource": {"package_id":"photos"},"fields": [{"id":"timestamp","type":"text"},{"id":"photo_id","type":"text"},{"id":"raw_url","type":"text"},{"id":"metadata","type":"text"}]}'

Simple Media Libraries (Collections on CSVs)
Contributor
1. Insert new row with timestamp/id/raw URL using Drupal or CKAN API
2. Done.

Server
1. Check CSV for new rows
2. Add row to search index
3. Write down last checked time
(Could recheck all, could reencode thumbnails by ID etc.)


