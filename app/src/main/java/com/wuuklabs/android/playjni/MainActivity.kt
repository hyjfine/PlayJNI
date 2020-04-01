package com.wuuklabs.android.playjni

import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {
    private val nativeUtil = NativeUtil()
    private var textView: TextView? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        textView = sample_text
        setupListener()
    }

    private fun setupListener() {
        findViewById<Button>(R.id.testString).setOnClickListener {
            val string = nativeUtil.testString("from java")
            textView?.text = string
        }
        findViewById<Button>(R.id.testByteArray).setOnClickListener {
            val array = byteArrayOf(6, 6, 6, 6, 6, 6)
            val byteArray = nativeUtil.testByteArray(array)
            val byteArrayString = byteArray.joinToString()
            textView?.text = byteArrayString
            Log.d(TAG, "----byteArray form native $byteArrayString")
        }
        findViewById<Button>(R.id.testCallBack).setOnClickListener {
            nativeUtil.setCallback { data ->
                textView?.text = data
            }
            val ret = nativeUtil.testNativeCallJava("from java")
            Log.d(TAG, "-----callback $ret")

        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    companion object {
        const val TAG = "MainActivity"
    }
}
