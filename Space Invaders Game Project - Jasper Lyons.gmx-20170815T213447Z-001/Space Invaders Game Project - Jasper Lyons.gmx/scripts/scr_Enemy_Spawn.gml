/// scr_Enemy_Spawn()

var xx = 128;
var yy = 64;

for (var i = 1; i <= 5; i++)
{
    for (var j = 1; j <= 11; j++) 
    {
        if (i == 1)
            instance_create(xx+(32*j), yy+(32*i), obj_Enemy_Top);            
        else if (i < 4)
            instance_create(xx+(32*j), yy+(32*i), obj_Enemy_Mid);            
        else
            instance_create(xx+(32*j), yy+(32*i), obj_Enemy_Bot);
    }
}
