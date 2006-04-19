program x;
var
   i,j,k : longint;
   w : array[0..8] of boolean; { false = original pos }
   level : longint;
   maxlevel : longint;
   { 0 = raft }
   { 1 = police ; 2 = theif ; 3 = mom ; 4 = dad ;
     5 = girl ; 6 = girl; 7 = boy ; 8 = boy ; }

procedure dump;
var i : longint;
begin
     for i := 0 to 8 do begin
         if w[i] then write(1) else write(0);
     end; writeln;
end;

function check : boolean;
var
   theifalone : boolean;
   i : longint;
begin
     check := false; { default false }

     { see if theif is alone }
     theifalone := true;
     for i := 1 to 8 do begin
         if i = 2 then continue;
         if (w[i] xor w[2] = false) then begin
            theifalone := false;
            break;
         end;
     end;

        { police != theif }    { theif alone! }
     if (w[1] xor w[2] = true) and (theifalone) then exit;
        { mom != dad }         { if mom with boy }
     if (w[3] xor w[4] = true) and ( (w[3] xor w[7] = false) or (w[3] xor w[8] = false) ) then exit;
        { mom != dad }         { if dad with girl }
     if (w[3] xor w[4] = true) and ( (w[3] xor w[7] = false) or (w[3] xor w[8] = false) ) then exit;

     check := true;
end;

function dfs(a,b : longint) : boolean;
label hell;
var
   i, j : longint;
   x : boolean;
begin
     j := 1;
     for i := 1 to 8 do begin
         if not w[i] then begin j := 0; break; end;
     end;
     if j = 1 then exit;
     dfs := false;
     if level > maxlevel then exit;

     inc(level);

     { cross a,b, and raft over }
     if (a > 0) then begin
          if a < 9 then w[a] := not w[a];
          w[b] := not w[b];
          w[0] := not w[0];
     end;
     if check = false then begin
        writeln('!');
        goto hell;
     end;
     writeln('dfs(',a,',',b,') ', maxlevel);

     dump;

     for i := 1 to 9 do begin
         for j := 1 to i-1 do begin
             if (i = a) and (j = b) then continue;
             x := dfs(i,j);
         end;
     end;

     hell:

     { reverse the situation }
     if (a > 0) then begin
          if a < 9 then w[a] := not w[a];
          w[b] := not w[b];
          w[0] := not w[0];
     end;

     dec(level);
end;


begin
     level := 0;
     for maxlevel := 1 to 100 do begin
          fillchar(w,sizeof(w),0);
          writeln('increasing maxlevel to', maxlevel);
          dfs(-1,-1);
     end;
end.
