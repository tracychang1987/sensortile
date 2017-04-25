/*******************************************************************************
 * COPYRIGHT(c) 2015 STMicroelectronics
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/
package com.st.BlueSTSDK.Example;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.text.method.ScrollingMovementMethod;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import com.st.BlueSTSDK.Feature;
import com.st.BlueSTSDK.Features.FeatureAcceleration;
import com.st.BlueSTSDK.Features.FeatureHumidity;
import com.st.BlueSTSDK.Features.FeaturePressure;
import com.st.BlueSTSDK.Features.FeatureSwitch;
import com.st.BlueSTSDK.Features.FeatureTemperature;
import com.st.BlueSTSDK.Manager;
import com.st.BlueSTSDK.Node;

import java.util.List;
/**
 * This simple activity show all the features available in a node.
 * When the user select one feature we request to receive the update notification and
 * we display it
 */
public class FeatureListActivity extends AppCompatActivity{

    private final static String NODE_FRAGMENT = FeatureListActivity.class.getCanonicalName() + "" +
            ".NODE_FRAGMENT";

    final static String NODE_TAG = FeatureListActivity.class.getCanonicalName() + "" +
            ".NODE_TAG";


    private Node nNode;
    private NodeContainerFragment nNodeContainer;
    Button button_temp,button_accx,button_press,button_switch;
    TextView textView_temp,textView_accx,textView_press,textView_switch;



    private Node.NodeStateListener nNodeStatusListener = new Node.NodeStateListener() {
        @Override
        public void onStateChange(final Node node, Node.State newState, Node.State prevState) {
            if (newState == Node.State.Connected) {
                FeatureListActivity.this.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        // populateFeatureList();
                        invalidateOptionsMenu(); //enable/disable the settings options
                    }//run
                });
            }//if*//*
        }
    };

    public static Intent getStartIntent(Context c, @NonNull Node node) {
        Intent i = new Intent(c, FeatureListActivity.class);
        i.putExtra(NODE_TAG, node.getTag());
        i.putExtras(NodeContainerFragment.prepareArguments(node));
        return i;
    }//getStartIntent

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_demo);

        button_temp   = (Button) findViewById(R.id.button_temp_id);
        textView_temp = (TextView) findViewById(R.id.textView_temp_id);

        button_accx   = (Button) findViewById(R.id.button_accx_id);
        textView_accx = (TextView) findViewById(R.id.textView_accx_id);
        textView_accx.setMovementMethod(ScrollingMovementMethod.getInstance());

        button_press = (Button) findViewById(R.id.button_press_id);
        textView_press  = (TextView) findViewById(R.id.textView_press_id);

        button_switch = (Button) findViewById(R.id.button_switch_id);
        textView_switch  = (TextView) findViewById(R.id.textView_switch_id);

        String nodeTag = getIntent().getStringExtra(NODE_TAG);
        nNode = Manager.getSharedInstance().getNodeWithTag(nodeTag);

        if (savedInstanceState == null) {
            Intent i = getIntent();
            nNodeContainer = new NodeContainerFragment();
            nNodeContainer.setArguments(i.getExtras());

            getFragmentManager().beginTransaction()
                    .add(nNodeContainer, NODE_FRAGMENT).commit();

        } else {
            nNodeContainer = (NodeContainerFragment) getFragmentManager()
                    .findFragmentByTag(NODE_FRAGMENT);

        }//if-else

    }

    public void button_temp_click(View view) {
        switch (view.getId()) {
            case R.id.button_temp_id:
                FeatureTemperature f = nNode.getFeature(FeatureTemperature.class);//get Feature Switch class
                 if(!nNode.isEnableNotification(f))//Ensure the Switch is EnableNotification
            {
                     nNode.enableNotification(f);
            }
            float tl=f.getTemperature(f.getSample());

            //  float tl = app.getF_temp();
           textView_temp.setText("当前温度为：");
                textView_temp.append(String.valueOf(tl));

        }
    }

    public void button_accx_click(View view) {
        switch (view.getId()) {
            case R.id.button_accx_id:
                FeatureAcceleration accx = nNode.getFeature(FeatureAcceleration.class);//get Feature Switch class
                if(!nNode.isEnableNotification(accx))//Ensure the Switch is EnableNotification
                {
                    nNode.enableNotification(accx);
                }
                float temp_x= accx.getAccX(accx.getSample());

                //  float tl = app.getF_temp();
               // textView_accx.setText(String.valueOf(tl));
                textView_accx.setText("X轴：");
                textView_accx.append(String.valueOf(temp_x));

                FeatureAcceleration accy = nNode.getFeature(FeatureAcceleration.class);//get Feature Switch class
                if(!nNode.isEnableNotification(accy))//Ensure the Switch is EnableNotification
                {
                    nNode.enableNotification(accy);
                }
                float temp_y= accy.getAccY(accy.getSample());

                textView_accx.append("Y轴：");
                textView_accx.append(String.valueOf(temp_y));

                FeatureAcceleration accz = nNode.getFeature(FeatureAcceleration.class);//get Feature Switch class
                if(!nNode.isEnableNotification(accz))//Ensure the Switch is EnableNotification
                {
                    nNode.enableNotification(accz);
                }
                float temp_z= accy.getAccZ(accz.getSample());

                textView_accx.append("Z轴：");
                textView_accx.append(String.valueOf(temp_z));

        }
    }

    public void button_press_click(View view) {
        switch (view.getId()) {
            case R.id.button_press_id:
                FeaturePressure f = nNode.getFeature(FeaturePressure.class);//get Feature Switch class
                if(!nNode.isEnableNotification(f))//Ensure the Switch is EnableNotification
                {
                    nNode.enableNotification(f);
                }
                float tl=f.getPressure(f.getSample());

                //  float tl = app.getF_temp();
                textView_press.setText("当前大气压为：");
                textView_press.append(String.valueOf(tl));

        }
    }

    public void button_switch_click(View view) {
        switch (view.getId()) {
            case R.id.button_switch_id:
                FeatureSwitch f = nNode.getFeature(FeatureSwitch.class);//get Feature Switch class
                if(!nNode.isEnableNotification(f))//Ensure the Switch is EnableNotification
                {
                    nNode.enableNotification(f);
                }
int i;
                if(f.getSwitchStatus(f.getSample())==0)
                {
                    f.changeSwitchStatus((byte)0x01);//点灯
                    i=0;
                }
                else
                {
                    f.changeSwitchStatus((byte) 0x00);
                    i=1;
                }

                //  float tl = app.getF_temp();
                textView_switch.setText("LED状态：");
                if(i==0)
                {
                    textView_switch.append("点亮");
                }
                else if(i==1)
                {
                    textView_switch.append("熄灭");
                }




        }
    }

    private void disableNeedNotification() {
        List<Feature> features = nNode.getFeatures();
        for (Feature f : features) {
            if (nNode.isEnableNotification(f))
                nNode.disableNotification(f);
        }//for sTestFeature
    }//disableNeedNotification

    @Override
    protected void onResume() {
        super.onResume();
        if (nNode.isConnected()) {
            //   populateFeatureList();
            invalidateOptionsMenu(); //enable/disable the settings options
        } else
            nNode.addNodeStateListener(nNodeStatusListener);

    }//onResume

    @Override
    protected void onPause() {

        //it is safe remove also if we didn't add it
        nNode.removeNodeStateListener(nNodeStatusListener);

        //if the node is already disconnected we don't care of disable the notification
        if (nNode.isConnected()) {
            disableNeedNotification();
        }//if

        super.onPause();
    }//stopDemo
}
