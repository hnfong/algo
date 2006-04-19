program p1008;
var
	i,j,n,m,k,t1,t2  : longint;
	course  : array[1..100] of string[30];
	student : array[1..100] of string[30];
	s : string;
	s1,s2 : string;
	app	: array[1..100,0..100] of longint;
begin
	fillchar(app,sizeof(app),0);
	k := 100;
	readln(n,m,k);

	{ read student names }
	for i := 1 to n do begin readln(student[i]); end;

	{ sort student names }
	for i := 1 to n do 
		for j := n downto 2 do
			if upcase(student[j-1]) > upcase(student[j]) then begin
				s := student[j-1];
				student[j-1] := student[j];
				student[j] := s;
			end;

	{ read course names }
	for i := 1 to m do begin readln(course[i]); end;

	{ process the applications }
	for i := 1 to k do begin
		readln(s);
		s1 := copy(s,1,pos(' ', s)-1);
		for j := 1 to n do begin
			if student[j] = s1 then t1 := j;
		end;
		s2 := copy(s,pos(' ', s)+1, length(s)-pos(' ', s));
		for j := 1 to m do begin
			if course[j] = s2 then t2 := j;
		end;
		inc(app[t2,0]);
		app[t2,t1] := 1;
	end;
	
	t1 := 0;
	for i := 1 to m do begin
		if app[i,0] > t1 then begin
			t1 := app[i,0];
			t2 := i;
		end;
	end;
	writeln(course[t2]);
	writeln(t1);
	for i := 1 to n do begin
		if app[t2,i] > 0 then writeln(student[i]);
	end;
end.
