package com.teamsf.zigbeetest;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;

public class MainActivity extends Activity implements OnClickListener 
{
	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		(findViewById ( R.id.main_btn_on )).setOnClickListener(this);
		(findViewById ( R.id.main_btn_off )).setOnClickListener(this);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	@Override
	public void onClick ( View v )
	{
		if ( v.getId() == R.id.main_btn_on )
		{
			Zigbee.onLEDNative((char)2);
		}
		
		else if ( v.getId() == R.id.main_btn_off )
		{
			Zigbee.offLEDNative((char)2);
		}
		
		else if ( v.getId() == R.id.main_btn_dim_up ) 
		{
			Zigbee.upDimNative((char)2);
		}
		
		else if ( v.getId() == R.id.main_btn_dim_down ) 
		{
			Zigbee.downDimNative((char)2);
		}
	}
}
