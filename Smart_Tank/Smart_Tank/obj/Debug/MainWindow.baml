   M S B A M L   `   `   `  ����U  QLiveCharts.Wpf, Version=0.9.7.0, Culture=neutral, PublicKeyToken=0bc1f845d1ebb8dfG4clr-namespace:LiveCharts.Wpf;assembly=LiveCharts.WpfLiveCharts.Wpf  5   	   E ASmart_Tank, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null'clr-namespace:Smart_Tank
Smart_Tank 5   	      Smart_Tank.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   Dlvc4clr-namespace:LiveCharts.Wpf;assembly=LiveCharts.Wpf     5   	   *localclr-namespace:Smart_Tank     5   	   U QWpfAnimatedGif, Version=2.0.0.0, Culture=neutral, PublicKeyToken=9e7cd3b544a090dc,gif"http://wpfanimatedgif.codeplex.com  5	   	     � 
ResizeMode$  NoResize=�5
   	    � Title$ 
MainWindow��5   	   $	��593��6   $
��1014��6)    � 	Resources 5         PrimaryBackgroundColor �� Color  SecundaryBackgroundColor  PrimaryBlueColor  PrimaryGrayColor  SecundaryBlueColor  SecundaryGrayColor  TertiaryBlueColor  ToggleButtonStyle �� 
TargetType �� Property �� Value �� 
TargetType ��Name	 �� CornerRadius
 A�Name �� Triggers :� RoutedEvent �� 
TargetName �� TargetProperty	 �� To g� Duration	 t� To P� Property P� Value �� 
TargetName��%  &	        &	 !     &	 B     &	 c     &	 �     &	 �     &	 �     &	 �     �� 5   
   $ #496FFF��69   �� 5   
   $ #FFFFFF��6;   �� 5   
   $ #263FAA��63   �� 5   
   $ #64677A��63   �� 5   
   $ #496FFF��65   �� 5   
   $ #CECECE��65   �� 5   
   $ #C2D1FC��64   �� 5   
   " d�6*   .�5      ��  � ��# �  6+   �� 5       � ��# �  6,   �� 5        � ��$ 20��6'   �� 5!       � ��$ 35��6&   �� 5"       � ��$ 20��6*   �� 5#       � ��$ 35��6)   �� 5$       � �� 5%      �� 5&      " d�6&   .R�5'      � .+�5(      �� $ Border��6%   #��z��5)   %   $	 7��5*   %   $��14��5+   %   $��35��5,   %   $��Center=�5-   %   $��Center=�5.   %   A� 5/      $
 Ellipse��6&   $��20��50   &   $��20��51   &   $��Center=�52   &   $
��Left=�53   &   #���  54   &   #��z��55   &   $��3��56   &   57       58      :� 5:      $ Checked��6+   .[�5;   "   �� .��5<   &   �� .��5=   *   �� $ Border��69   $1 +(Border.Background).(SolidColorBrush.Color)�5>   9   $ #C2D1FCX�5?   9   $ 0:0:0.2D�6F   t� 5@   *   $ Ellipse��6=   $ Margin�5A   =   $ 15 0 0 0X�5B   =   $ 0:0:0.2D�6K   5C   '   5D   #   5E      :� 5H      $ 	Unchecked��6+   .[�5I   "   �� .��5J   &   �� .��5K   *   �� $ Border��69   $1 +(Border.Background).(SolidColorBrush.Color)�5L   9   $ #CECECEX�5M   9   $ 0:0:0.2D�6F   t� 5N   *   $ Ellipse��6=   $ Margin�5O   =   $ 0 0 0 0X�5P   =   $ 0:0:0.2D�6J   5Q   '   5R   #   5S      P� 5T       �@d�	IsChecked$
 TrueY�6;   . �5U   "   �� $ Ellipse��6)   # �  5W   )    � ���� 5X   "   $ Ellipse��6)   # �  5Z   )    � ��5[      5]      5_      5a      5c      .��5d      � $��0,0,0,-6q�6   $
��1014��6   .+�5e   
   � $	��462��6   $��143,0,120,79q�6   $��Bottom=�62   $	��NaN��6M   .+�5f      �� -   5        $ bdrWaterLevel��5f      $��1q�6,   $��0��6@   $	 	0,0,20,20��6M   ���#CAC3F4$��
58,0,91,81q�6{   $	��602��6�   $��50��6�   $��Bottom=�6�   �� 5h      -   5         ��Name$ image��5h      $
��Left=�6#   $	��307��6>   $��0,96,0,0q�6K   $	��Top=�6]   $	��743��6u   $��/images/tank.png��6�   �� 5i      -   5        $ image1��5i      $
��Left=�6$   $	��100��6?   $��651,109,0,0q�6L   $	��Top=�6a   $	��100��6y   $��/images/valve.png��6�   �� 5j      -   5        $ image1_Copy��5j      $
��Left=�6)   $	��100��6D   $��651,309,0,0q�6Q   $	��Top=�6f   $	��100��6~   $��/images/valve.png��6�   �� 5k      -   5        $ 
imgWaterIn��5k      "  WpfAnimatedGif.ImageBehavior   RepeatBehavior$ Forever��6(      AnimatedSource$ /images/water In.gif��6S   $
��Left=�6�   $��13��6�   $��665,145,0,0q�6�   $	��Top=�6�   $��76��6�   $��/images/water In.gif��6�   $y�	Collapsed=�6  �� 5l      -   5        $ image3��5l      $
��Left=�6$   $��40��6?   $��148,333,0,0q�6K   $	��Top=�6`   $��40��6x   $��/images/oxygen motor.png��6�   �� 5m      -   5        $ image3_Copy��5m      $
��Left=�6)   $��53��6D   $��
247,0,0,85q�6P   $��Bottom=�6d   $��44��6   $��/images/water filter.png��6�   �� 5n      -   5        $ imgLight��5n      $
��Left=�6&   $��47��6A   $��	108,0,0,0q�6M   $	��Top=�6`   $	��512��6x   $��/images/light.png��6�   �� 5o      -	   5        $ imgOxygenBubble��5o      $ Forever��6-   $ /images/oxygen bubble.gif��6X   $
��Left=�6�   $	��241��6�   $��
72,163,0,0q�6�   $	��Top=�6�   $	��181��6�   $��/images/oxygen bubble.gif��6�   $y�	Collapsed=�6  �� 5p      -
   5         ��Name$ tglValveOut��5p      $	��Top=�6,   $
��Left=�5q      #���  5r      $��683,289,0,0q�6=    J� RenderTransformOrigin$ 
0.543,0.69&�6R   6u   �� 5s      -   5        $ 
tglValveIn��5s      $	��Top=�6+   $
��Left=�5t      #���  5u      $��683,183,0,0q�6=   $ 1.266,0.185&�6R   6v   �� 5v      -   5        $ tglWaterFilter��5v      $	��Top=�6/   $
��Left=�5w      #���  5x      $��251,408,0,0q�6=   6R   �� 5y      -   5        $ tglOxygenMotor��5y      $	��Top=�6/   $
��Left=�5z      #���  5{      $��151,408,0,0q�6=   6R   �� 5|      -   5        $ tglLight��5|      $	��Top=�6)   $
��Left=�5}      #���  5~      $��
342,39,0,0q�6=   6Q   �� 5      -   5         ��Name$ label��5      $��Light��6#   $
��Left=�63   $��
341,56,0,0q�6N   $	��Top=�6b   �� 5�      -   5        $ 
label_Copy��5�      $��Water Filter��6(   $
��Left=�6?   $��234,436,0,0q�6Z   $	��Top=�6o   $
��Bold"�6�   �� 5�      -   5        $ label_Copy1��5�      $��Oxygen Motor��6)   $
��Left=�6@   $��125,436,0,0q�6[   $	��Top=�6p   $
��Bold"�6�   �� 5�      -   5        $ imgWaterOut��5�      $ Forever��6)   $ /images/water Out.gif��6T   $
��Left=�6�   $��13��6�   $��665,345,0,0q�6�   $	��Top=�6�   $��76��6�   $��/images/water Out.gif��6�   $y�	Collapsed=�6  �� 5�      -   5         ��Name$ textBox��5�      $
��Left=�6'   $��23��6B   $��
432,49,0,0q�6N    �� TextWrapping$
 Wrap=�6b   $��TextBox��6v   $	��Top=�6�   $	��188��6�   5�      �� 5�   
   -   5         ��Name$ button��5�      $��Button��6!   $
��Left=�62   $��
941,16,0,0q�6M   $	��Top=�6a   $��43��6y   $��63��6�   6�   � 5�   
   $	��300��6   $	��150��6   .+�5�      #   LiveCharts.Wpf.CartesianChart  $��10,-117,-10,117q�6!   &    LiveCharts.Wpf.Charts.Base.Chart   Series 5�         LiveCharts.Wpf.LineSeries     LiveCharts.Wpf.Series   Stroke
 ��  �    Values  6%   �� *Values+6?   5�      5�      5�      5�      