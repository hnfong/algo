program fsckingjudge;
{
	@JUDGE_ID:  20044WC 10343 PASCAL "Siliconism"
}
type	tn = array[1..10] of byte;
	tc = array[1..10] of char;
	str4 = string[4];
const
hc : array[1..64] of char = (
'A', 'B', 'C', 'D', 'E', 
'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 
'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 
'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 
't', 'u', 'v', 'w', 'x', 'y', 'z', '0', 
'1', '2', '3', '4', '5', '6', '7', '8', 
'9', '+', '/'
);
	shl2 = 63; shl4 = 15; shl6 = 3;
var 
	c : char;
	i : longint;
	s4 : string[4];
	empty, toexit,tocontinue : boolean;
	numofpad : longint;
procedure blackhole(x : string) ; begin end;

function notintable(c : char) : boolean;
begin
	notintable := false;
	if (c >= '0') and (c <= '9') then exit;
	if (c >= 'A') and (c <= 'Z') then exit;
	if (c >= 'a') and (c <= 'z') then exit;
	if (c = '/') then exit;
	if (c = '+') then exit;
	if (c = '#') then exit;
	if (c = '=') then exit;
	notintable := true;
end;

function b64tonum(x : string) : tn; var ret : tn ; i,j : longint; 
begin fillchar(ret, sizeof(ret), 0); 
	for i := 1 to 4 do begin
		if x[i] = '=' then begin
			inc(numofpad);
		end;
		for j := 1 to 64 do begin
			if hc[j] = x[i] then begin ret[i]:= j-1; end;
		end;
	end;
	b64tonum := ret;
end; 

function fourtothree(x : tn) : tn; var tmp : tn; begin fillchar(tmp, sizeof(tmp), 0);
tmp[1] := (x[1] and shl2) shl 2; tmp[1] := tmp[1] or (x[2] shr 4);
tmp[2] := (x[2] and shl4) shl 4; tmp[2] := tmp[2] or (x[3] shr 2);
tmp[3] := (x[3] and shl6) shl 6; tmp[3] := tmp[3] or (x[4]);
fourtothree := tmp; end;

function numtoasc(x : tn) : str4; var s : string[4]; i : longint; begin 
	s := '   '; for i := 1 to 3 do begin s[i] := chr(x[i]); end; numtoasc := s; end;

procedure display(x : string);
begin
	if numofpad > 0 then begin
		if numofpad = 1 then write(x[1],x[2]);
		if numofpad = 2 then write(x[1]);
	end else
		write(x[1],x[2],x[3]);
end;

begin
	while not eof do begin
		fillchar(s4, sizeof(s4), 0);
		s4 := '    ';
		i :=0;
		toexit := true;
		numofpad := 0;
		tocontinue := false;
		empty := true;
		while not eof do begin
			if i >= 4 then begin toexit := false; break; end;
			read(c);
			if c = '#' then begin 
				if not empty then write('#');
				toexit:=false ; tocontinue := true; break;
			end;
			empty := false;
			if notintable(c) then continue;
			inc(i);
			s4[i] := c;
		end;
		if tocontinue then continue;
		if toexit then begin exit; end;
		display(numtoasc(fourtothree(b64tonum (s4))));
	end;
end.

