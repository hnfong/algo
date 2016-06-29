#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <strings.h>
using namespace std;


#define dprintf(...) // printf
#define d2printf(...) // printf

struct lexstr
{
  bool operator()(const string s1, const string s2) const
  {
    return strcasecmp(s1.c_str(), s2.c_str()) < 0;
  }
};

vector <char *> splitter ( char * s ) {
	vector < char * > k;
	char * t;
	d2printf("!! ");
	while ( true ) {
		t = strstr(s, ",");
		if (t != NULL) *t = 0;
		d2printf("[%s] ", s);
		k.push_back(s);
		if (t == NULL) break;
		s = t + 1;
	};
	d2printf("!! \n");
	return k;
};

set < string, lexstr > record_list;
set < string, lexstr > field_list;
map < string, map<string, string > > data_map;
map < string, int > field_count;
map < string, int > record_count;

void show_action( string r, string f ) {
	dprintf("Show action: [%s] [%s]\n", r.c_str(), f.c_str());
	dprintf("Field count: %d, Record count: %d\n", field_count[f], record_count[r]);
	//cout << r << endl;
	//cout << f << endl;
	printf("%s\n", r.c_str());
	printf("%s\n", f.c_str());
	if (data_map[r][f] == "") {
	//	cout << "NO DATA" << endl;
		printf("NO DATA\n");
	} else {
		//cout << data_map[r][f];
		printf("%s", data_map[r][f].c_str());
	};

	//cout << "." << endl;
	printf(".\n");
};

void show_record( string r, const char *fld ) {
	if (strcmp(fld, "*") == 0) {
		for (set<string>::iterator i = field_list.begin(); i != field_list.end(); i++ ) {
			show_action(r, *i);
		};
	} else {
		char fld2[300]; strcpy(fld2, fld);
		vector< char * > flds = splitter(fld2);
		for ( vector<char *>::iterator i = flds.begin(); i != flds.end(); i++) {
			show_action(r, string(*i));
		};
	};
};

void delete_action( string r, string f) {
	dprintf("Delete action: [%s] [%s]\n", r.c_str(), f.c_str());
	if (data_map[r][f] == "") {
		dprintf("--> Note: nothing to delete\n");
		// nothing to delete.
	} else {
		// sth to delete
		dprintf("deleted!\n");
		data_map[r][f] = "";
		
		field_count[f]--;
		if (field_count[f] == 0)  {field_list.erase(f); dprintf("erased field [%s]\n", f.c_str()); };
		
		record_count[r]--;
		if (record_count[r] == 0) {record_list.erase(r); dprintf("erased record [%s]\n", r.c_str()); };
		
		dprintf("Field count: %d, Record count: %d\n", field_count[f], record_count[r]);
	};
};

void delete_record( string r, const char *fld ) {
	if (strcmp(fld, "*") == 0) {
		for (set<string>::iterator i = field_list.begin(); i != field_list.end(); i++ ) {
			delete_action( r, *i );
		};
	} else {
		char fld2[300]; strcpy(fld2, fld);
		vector< char * > flds = splitter(fld2);
		for ( vector<char *>::iterator i = flds.begin(); i != flds.end(); i++) {
			delete_action( r, string(*i) );
		};
	};
};

void append_action ( string r, string f, const char * data) {
	dprintf("Append Action: [%s] [%s]\n", r.c_str(), f.c_str());
	
	if (data_map[r][f] == "") {
		field_list.insert(f);
		field_count[f]++;
		
		record_list.insert(r);
		record_count[r]++;
		
		dprintf("[New]\n");
	} else {
		dprintf("[Existing]\n");
	};
	dprintf("Field count: %d, Record count: %d\n", field_count[f], record_count[r]);
	
	data_map[r][f] = data_map[r][f] + string(data);
};

void append_record( string r, const char * fld, const char * data)  {
	if (strcmp(fld, "*") == 0) {
		for (set<string>::iterator i = field_list.begin(); i != field_list.end(); i++ ) {
			append_action( r, *i, data );
		};
	} else {
		char fld2[300]; strcpy(fld2, fld);
		vector< char * > flds = splitter(fld2);
		for ( vector<char *>::iterator i = flds.begin(); i != flds.end(); i++) {
			append_action( r, string(*i), data );
		};
	};
};


int main() {
	char buf[300];

	while (!feof(stdin)) {
		fgets(buf, 300, stdin);
		if (strncmp(buf, "done", 4) == 0 ) break;
		buf[strlen(buf)-1] = 0;
		
		if (strncmp(buf, "rem ", 4) == 0) continue;
		if (strcmp(buf, ".") == 0 ) continue;

		dprintf("[%s]\n", buf);
		
		char *rec, *fld;
		rec = strstr(buf, " "); *rec = 0; rec++; 
		fld = strstr(rec, " "); *fld = 0; fld ++;


		dprintf("**********************************************\n");
		//dprintf("Records: [%s]\n", rec);
		//dprintf("Fields : [%s]\n", fld);
		
		if (strcmp(buf, "append") == 0) {
			//dprintf("Action : Append\n");

			char data[2000*260];
			memset(data,0,sizeof(data));
			while (true) {
				char buf2[300];
				fgets(buf2, 300, stdin);
				if (strcmp(buf2, ".\n") == 0) { break; };
				strcat(data,buf2);
			};
			dprintf("DATA:\n<<<%s>>>\n", data);
			
			if (strcmp(rec,"*") == 0 ) {
				for ( set<string>::iterator i = record_list.begin();  i != record_list.end() ; i++ ) {
					append_record( *i , fld, data );
				};
			} else {
				vector< char * > recs = splitter(rec);
				for ( vector< char * >::iterator i = recs.begin() ; i != recs.end(); i ++ ) {
					append_record( string(*i), fld, data);
				};
			};

		} else if (strcmp(buf, "show")== 0) {
			//dprintf("Action : Show\n");
			
			if (strcmp(rec, "*") == 0) {
				for ( set < string >::iterator i = record_list.begin() ; i != record_list.end(); i++ ) {
					show_record( *i, fld );
				};
			} else {
				vector< char * > recs = splitter(rec);
				for ( vector <char *>::iterator i = recs.begin(); i != recs.end(); i++ ) {
					show_record( string( *i) , fld );
				};
			};
			printf( "*\n");
		} else if (strcmp(buf, "delete") == 0) {
			//dprintf("Action : Delete\n");

			if (strcmp(rec, "*") == 0) {
				for ( set < string >::iterator i = record_list.begin(); i != record_list.end(); i++) { 
					delete_record( *i, fld);
				};
			} else {
				vector< char * > recs = splitter(rec);
				for ( vector <char *>::iterator i = recs.begin(); i != recs.end(); i++ ) {
					delete_record( string( *i) , fld );
				};
			};

		} else {
			//dprintf("Fucked, dunno the cmd!\n");
			//throw(0);
		};
	};
};
