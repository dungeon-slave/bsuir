package com.example.qr_generator;

import android.graphics.Bitmap;
import com.google.zxing.BarcodeFormat;
import com.google.zxing.EncodeHintType;
import com.google.zxing.MultiFormatWriter;
import com.google.zxing.common.BitMatrix;
import com.journeyapps.barcodescanner.BarcodeEncoder;
import java.util.Hashtable;

public class GeneratorQR
{
    private BitMatrix matrix;
    public Bitmap generate(String text)
    {
        BarcodeEncoder encoder = new BarcodeEncoder();
        try
        {
            MultiFormatWriter writer = new MultiFormatWriter();
            Hashtable<EncodeHintType, Object> hints = new Hashtable<>();
            hints.put(EncodeHintType.CHARACTER_SET, "UTF-8");
            matrix = writer.encode(text, BarcodeFormat.QR_CODE, 400, 400, hints);
        }
        catch (Exception e)
        {
            new RuntimeException();
        }

        return encoder.createBitmap(matrix);
    }
}
