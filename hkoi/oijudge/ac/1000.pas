program p1000;
const debug = false;
var
	i,j,k,n,ni : longint;
	s : string;
	data : string;
	cmd : string;
	param : string;
	param1 : string;
	param2 : string;
	oper : string;
function deq(s : string) : string; begin deq := copy(s,2,length(s)-2); end;
function mypos(s:string; c : char; x : longint) : longint;
var	i : longint;
begin
	for i := x to length(s) do begin
		if s[i] = c then begin
			mypos := i;
			exit;
		end;
	end;
end;
function quote1 : longint;
begin
	quote1 := mypos(s,'"',1);
end;
function quote2 : longint;
begin
	quote2 := mypos(s,'"', quote1+1);
end;
function trim(s : string) : string;
var i : longint; k : longint;
begin
	for i := length(s) downto 1 do begin
		if s[i]<>' ' then begin
			k := i;
			break;
		end;
	end;
	for i := 1 to k do begin
		if s[i] <> ' ' then begin
			trim := copy(s, i, k-i+1);
			exit;
		end;
	end;
end;
procedure xwriteln(s : string); begin writeln('"',s,'"'); end;

begin
	readln(n);
	for ni := 1 to n do begin
		readln(s);
		data := (copy(s,quote1+1, quote2-quote1-1));
		
		cmd := copy(s, quote2+1, length(s)-quote2);
		cmd := trim(cmd);
	
		oper := copy(cmd, 1,  mypos(cmd, ' ', 1)-1);
		
		param := cmd;
		delete(param, 1, length(oper));
		param := trim(param);

		if debug then begin
			xwriteln(data);
			xwriteln(cmd);
			xwriteln(oper);
			xwriteln(param);
		end;

		write('Command #', ni,': ');
		if upcase(oper) = 'CUT' then begin
			param1 := deq(param);
			if pos('"', param1) > 0 then param1 := copy(param1, 1, pos('"', param1)-1);
			if pos(param1,data) > 0 then delete(data, pos(param1, data), length(param1));
		end;

		if upcase(oper) = 'APPEND' then begin
			param1 := deq(param);
			if pos('"', param1) > 0 then param1 := copy(param1, 1, pos('"', param1)-1);
			data := data + param1;
		end;

		if upcase(oper) = 'INSERT' then begin
			param1 := copy(param,1,pos(' ', param)-1);
			param2 := param;
			delete(param2, 1, length(param1));
			param2 := deq(trim(param2));
			if pos('"', param2) > 0 then param2 := copy(param2, 1, pos('"', param2)-1);
			val(param1, k, j);
			data := copy(data,1, k-1) + param2 + copy(data, k, length(data)-k+1);
		end;

		if upcase(oper) = 'REPLACE' then begin
			param1 := copy(param,2, mypos(param,'"',2)-2);
			param2 := param;
			delete(param2,1,length(param1)+2);
			param2 := deq(trim(param2));
			if pos(param1,data) > 0 then begin
			data := copy(data,1, pos(param1,data)-1) + param2 + copy(data, pos(param1,data)+length(param1), length(data)-pos(param1,data)+length(param1));
			end;
		end;
		xwriteln(data);
	end;
end.

