program program2;
var
	i : longint;
	n : longint;
	m : longint;
	u : array[1..3000] of string[10];
	s : string[10];
	f : text;

function userexists(a : string[10]) : boolean;
var
	h,t,m,i : longint;
begin
	userexists := true;
	for i := 1 to n do begin
		if u[i] = a then exit;
	end;
	userexists := false;
	exit;

	userexists := true;
	h := 1;
	t := n;
	if (u[n] = a) then exit;
	while (h <> t) do begin
		m := (h+t) div 2;
		if u[m] = a then exit;
		if u[m] < a then h := m+1;
		if u[m] > a then t := m;
	end;
	userexists := false;
end;

begin
	assign(f, 'USER.TXT');
	reset(f);
	readln(f, n);
	for i := 1 to n do begin
		readln(f,u[i]);
	end; close(f); 
	
	assign(input, 'DIR.TXT');
	reset(input);
	assign(output, 'REMOVE.TXT');
	rewrite(output);
	readln(m);
	for i := 1 to m do begin
		readln(s);
		if not userexists(s) then writeln(s);
	end;
	close(input);
	close(output);
end.

