program p186;
{
	@JUDGE_ID: 20044WC 186 PASCAL "DaP/DyP"
}
var
	a,b,i,j,k : longint;
	w : array[1..100,1..100] of longint;
	bt : array[1..100,1..100] of longint;
	nam : array[1..100] of string[20];
	routename : array[1..100,1..100] of string[10];
	s : string[30];
	n : longint;
	c : char;
	t : longint;
	ni : longint;

function setgetname(s:string): longint;var i : longint;
begin
	for i := 1 to n do begin
		if s = nam[i] then begin
			setgetname := i;
			exit;
		end;
	end;
	inc(n);
	nam[n] := s;
	setgetname := n;
end;

procedure back(a,b:longint);var i : longint;
begin
	if bt[a,b] = 0 then begin
		write(nam[a]);
		for i := 1 to 21 - length(nam[a]) do write(' ');
		write(nam[b]);
		for i := 1 to 21 - length(nam[b]) do write(' ');
		write(routename[a,b]);
		for i := 1 to 11 - length(routename[a,b]) do write(' ');
		writeln(w[a,b]:5);
		exit;
	end;
	back(a,bt[a,b]);
	back(bt[a,b],b);
end;

begin
	for i := 1 to 100 do
		for j := 1 to 100 do
			w[i,j] := 99999999;
	n := 0;
	{ read input }
	while true do begin
		{ 1st field }
		s := '';
		while true do begin
			read(c);
			if c = ',' then break;
			s := s + c;
		end;
		a := setgetname(s);
		{ 2nd field }
		s := '';
		while true do begin
			read(c);
			if c = ',' then break;
			s := s + c;
		end;
		b := setgetname(s);
		{ 3rd field }
		s := '';
		while true do begin
			read(c);
			if c = ',' then break;
			s := s+ c;
		end;
		{ 4th field }
		readln(t);

		{ process input }
		if t < w[a,b] then begin
		w[a,b] := t;
		w[b,a] := t;
		routename[a,b] := s;
		routename[b,a] := s;
		end;
		if eoln then break;
	end;
	{ end of path input }
	readln;
	{ floyd! }
	for k := 1 to n do
	for i := 1 to n do
	for j := 1 to n do
		if w[i,k]+w[k,j]<w[i,j] then begin
			w[i,j] := w[i,k]+w[k,j];
			bt[i,j] := k;
		end;
	{ start of request input }
	ni := 0;
	while not eof do begin
		inc(ni);
		{ 1st field }
		s := '';
		while true do begin
			read(c);
			if c = ',' then break;
			s := s + c;
		end;
		a := setgetname(s);
		{ 2nd field }
		s := '';
		while not eoln do begin
			read(c);
			if c = ',' then break;
			s := s + c;
		end;
		readln;
		b := setgetname(s);

		{ output our work }
		writeln;
		writeln;
		writeln('From                 To                   Route      Miles');
		writeln('-------------------- -------------------- ---------- -----');
		back(a,b); { back tracking }
		writeln('                                                     -----');
		writeln('                                          Total      ',w[a,b]:5);
	end;
	{ ends the crap }
end.
