set(SOURCES DDSImage.cpp
            DirectXGraphics.cpp
            DirtyRegionSolvers.cpp
            DirtyRegionTracker.cpp
            FFmpegImage.cpp
            GraphicContext.cpp
            GUIAction.cpp
            GUIAudioManager.cpp
            GUIBaseContainer.cpp
            GUIBorderedImage.cpp
            GUIButtonControl.cpp
            GUICheckMarkControl.cpp
            GUIColorManager.cpp
            GUIControl.cpp
            GUIControlFactory.cpp
            GUIControlGroup.cpp
            GUIControlGroupList.cpp
            GUIControlProfiler.cpp
            GUIDialog.cpp
            GUIEditControl.cpp
            GUIFadeLabelControl.cpp
            GUIFixedListContainer.cpp
            GUIFont.cpp
            GUIFontCache.cpp
            GUIFontManager.cpp
            GUIFontTTF.cpp
            GUIImage.cpp
            GUIIncludes.cpp
            GUIInfoTypes.cpp
            GUIKeyboardFactory.cpp
            GUILabelControl.cpp
            GUILabel.cpp
            GUIListContainer.cpp
            GUIListGroup.cpp
            GUIListItem.cpp
            GUIListItemLayout.cpp
            GUIListLabel.cpp
            GUIMessage.cpp
            GUIMoverControl.cpp
            GUIMultiImage.cpp
            GUIMultiSelectText.cpp
            GUIPanelContainer.cpp
            GUIProgressControl.cpp
            GUIRadioButtonControl.cpp
            GUIRenderingControl.cpp
            GUIResizeControl.cpp
            GUIRSSControl.cpp
            GUIScrollBarControl.cpp
            GUISelectButtonControl.cpp
            GUISettingsSliderControl.cpp
            GUISliderControl.cpp
            GUISpinControl.cpp
            GUISpinControlEx.cpp
            GUIStaticItem.cpp
            GUITextBox.cpp
            GUITextLayout.cpp
            GUITexture.cpp
            GUIToggleButtonControl.cpp
            GUIVideoControl.cpp
            GUIVisualisationControl.cpp
            GUIWindow.cpp
            GUIWindowManager.cpp
            GUIWrappingListContainer.cpp
            imagefactory.cpp
            IWindowManagerCallback.cpp
            LocalizeStrings.cpp
            Resolution.cpp
            Shader.cpp
            StereoscopicsManager.cpp
            TextureBundle.cpp
            TextureBundleXBT.cpp
            Texture.cpp
            TextureManager.cpp
            VisibleEffect.cpp
            XBTF.cpp
            XBTFReader.cpp)

set(HEADERS DDSImage.h
            DirectXGraphics.h
            DirtyRegion.h
            DirtyRegionSolvers.h
            DirtyRegionTracker.h
            DispResource.h
            FFmpegImage.h
            Geometry.h
            GraphicContext.h
            gui3d.h
            GUIAction.h
            GUIAudioManager.h
            GUIBaseContainer.h
            GUIBorderedImage.h
            GUIButtonControl.h
            GUICallback.h
            GUICheckMarkControl.h
            GUIColorManager.h
            GUIControl.h
            GUIControlFactory.h
            GUIControlGroup.h
            GUIControlGroupList.h
            GUIControlProfiler.h
            GUIDialog.h
            GUIEditControl.h
            GUIFadeLabelControl.h
            GUIFixedListContainer.h
            GUIFont.h
            GUIFontCache.h
            GUIFontManager.h
            GUIFontTTF.h
            GUIImage.h
            GUIIncludes.h
            GUIInfoTypes.h
            GUIKeyboard.h
            GUIKeyboardFactory.h
            GUILabel.h
            GUILabelControl.h
            GUIListContainer.h
            GUIListGroup.h
            GUIListItem.h
            GUIListItemLayout.h
            GUIListLabel.h
            GUIMessage.h
            GUIMoverControl.h
            GUIMultiImage.h
            GUIMultiSelectText.h
            GUIPanelContainer.h
            GUIProgressControl.h
            GUIRadioButtonControl.h
            GUIRenderingControl.h
            GUIResizeControl.h
            GUIRSSControl.h
            GUIScrollBarControl.h
            GUISelectButtonControl.h
            GUISettingsSliderControl.h
            GUISliderControl.h
            GUISpinControl.h
            GUISpinControlEx.h
            GUIStaticItem.h
            GUITextBox.h
            GUITextLayout.h
            GUITexture.h
            GUIToggleButtonControl.h
            GUIVideoControl.h
            GUIVisualisationControl.h
            GUIWindow.h
            GUIWindowManager.h
            GUIWrappingListContainer.h
            IAudioDeviceChangedCallback.h
            IDirtyRegionSolver.h
            IGUIContainer.h
            iimage.h
            imagefactory.h
            IMsgTargetCallback.h
            IRenderingCallback.h
            ISliderCallback.h
            IWindowManagerCallback.h
            LocalizeStrings.h
            Resolution.h
            Shader.h
            StereoscopicsManager.h
            Texture.h
            TextureBundle.h
            TextureBundleXBT.h
            TextureManager.h
            TransformMatrix.h
            Tween.h
            VisibleEffect.h
            WindowIDs.h
            XBTF.h
            XBTFReader.h)

if(OPENGL_FOUND)
  list(APPEND SOURCES GUIFontTTFGL.cpp
                      GUITextureGL.cpp
                      MatrixGLES.cpp
                      TextureGL.cpp)
  list(APPEND HEADERS GUIFontTTFGL.h
                      GUITextureGL.h
                      MatrixGLES.h
                      TextureGL.h)
endif()

if(OPENGLES_FOUND)
  list(APPEND SOURCES GUIFontTTFGL.cpp
                      GUIShader.cpp
                      GUITextureGLES.cpp
                      MatrixGLES.cpp
                      TextureGL.cpp
                      TexturePi.cpp)
  list(APPEND HEADERS GUIFontTTFGL.h
                      GUIShader.h
                      GUITextureGLES.h
                      MatrixGLES.h
                      TextureGL.h
                      TexturePi.h)
endif()

if(CORE_SYSTEM_NAME STREQUAL windows)
  list(APPEND SOURCES D3DResource.cpp
                      GUIFontTTFDX.cpp
                      GUIShaderDX.cpp
                      GUITextureD3D.cpp
                      TextureDX.cpp)
  list(APPEND HEADERS D3DResource.h
                      GUIFontTTFDX.h
                      GUIShaderDX.h
                      GUITextureD3D.h
                      TextureDX.h)
endif()

core_add_library(guilib)
add_dependencies(guilib libcpluff)

if(ENABLE_INTERNAL_FFMPEG)
  add_dependencies(guilib ffmpeg)
endif()

if(CORE_SYSTEM_NAME STREQUAL windows)
  set(SHADERS_VERTEX guishader_vert.hlsl)
  set(SHADERS_PIXEL guishader_checkerboard_right.hlsl
                    guishader_checkerboard_left.hlsl
                    guishader_default.hlsl
                    guishader_fonts.hlsl
                    guishader_interlaced_right.hlsl
                    guishader_interlaced_left.hlsl
                    guishader_multi_texture_blend.hlsl
                    guishader_texture.hlsl
                    guishader_texture_noblend.hlsl
                    guishader_video.hlsl
                    guishader_video_control.hlsl)
  foreach(shader ${SHADERS_VERTEX})
    add_shader_dx(guilib
                  ${CORE_SOURCE_DIR}/system/shaders/${shader}
                  vs_4_0_level_9_1
                  VS)
  endforeach()
  foreach(shader ${SHADERS_PIXEL})
    add_shader_dx(guilib
                  ${CORE_SOURCE_DIR}/system/shaders/${shader}
                  ps_4_0_level_9_1
                  PS)
  endforeach()
  add_dependencies(guilib d3dx11effects)
endif()
