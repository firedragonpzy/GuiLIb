/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.sweetpome.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "CocoLoadingBar.h"
#include "DictionaryHelper.h"

namespace cs {
    
    CocoLoadingBar::CocoLoadingBar():
    m_nBarType(0),
    m_nPercent(100),
    m_fTotalLength(0),
    m_fBarHeight(0),
    m_pRenderBar(NULL)
    {
		//this->m_nWidgetType = 2;
    }
    
    CocoLoadingBar::~CocoLoadingBar()
    {
        
    }
    
    CocoLoadingBar* CocoLoadingBar::create()
    {
//        return CocoLoadingBar::create(NULL);
        CocoLoadingBar* widget = new CocoLoadingBar();
        if (widget && widget->init()) {
            return widget;
        }
        CC_SAFE_DELETE(widget);
        return NULL;
    }
    
    bool CocoLoadingBar::init()
    {
        if (CocoWidget::init()) {
            this->m_pRenderBar = new UISprite();
            this->m_pRenderBar->init();
            this->addUIElement(this->m_pRenderBar);
            this->m_pRenderBar->setAnchorPoint(ccp(0.0,0.5));
            return true;
        }
        return false;
    }
    
    void CocoLoadingBar::setDirection(int dir)
    {
        if (this->m_nBarType == dir) {
            return;
        }
        this->m_nBarType = dir;

        switch (this->m_nBarType){
            case 0:
                this->m_pRenderBar->setAnchorPoint(ccp(0.0,0.5));
				this->m_pRenderBar->setPosition(ccp(-this->m_fTotalLength*0.5f,0.0f));
				this->m_pRenderBar->setFlipX(false);
                break;
            case 1:
				
                this->m_pRenderBar->setAnchorPoint(ccp(1.0,0.5));
				this->m_pRenderBar->setPosition(ccp(this->m_fTotalLength*0.5f,0.0f));
				this->m_pRenderBar->setFlipX(true);

                break;
        }
    }
    
    int CocoLoadingBar::getDirection()
    {
        return this->m_nBarType;
    }
    
    void CocoLoadingBar::setTexture(const char* texture,bool useSpriteFrame)
    {
        this->m_pRenderBar->loadTexture(texture,useSpriteFrame);
        this->m_fTotalLength = this->m_pRenderBar->getContentSize().width;
        this->m_fBarHeight = this->m_pRenderBar->getContentSize().height;

		switch (this->m_nBarType){
		case 0:
			this->m_pRenderBar->setAnchorPoint(ccp(0.0,0.5));
			this->m_pRenderBar->setPosition(ccp(-this->m_fTotalLength*0.5f,0.0f));
			this->m_pRenderBar->setFlipX(false);
			break;
		case 1:
			this->m_pRenderBar->setAnchorPoint(ccp(1.0,0.5));
			this->m_pRenderBar->setPosition(ccp(this->m_fTotalLength*0.5f,0.0f));
			this->m_pRenderBar->setFlipX(true);
			break;
		}
    }
    
    void CocoLoadingBar::setPercent(int percent)
    {
        if ( percent < 0 || percent > 100){
            return;
        }
        if (this->m_fTotalLength <= 0){
            return;
        }
        this->m_nPercent = percent;
        float res = this->m_nPercent/100.0;
		this->m_pRenderBar->setRect(0,0,this->m_fTotalLength*res,this->m_fBarHeight);

    }
    
    int CocoLoadingBar::getPercent()
    {
        return this->m_nPercent;
    }
    
    CRenderNode* CocoLoadingBar::getValidNode()
    {
        return this->m_pRenderBar->getCRenderNode();
    }
    
    void CocoLoadingBar::setColor(int r, int g, int b)
    {
        this->m_pRenderBar->setColor(r, g, b);
    }
    
    void CocoLoadingBar::setOpacity(int opcity)
    {
        this->m_pRenderBar->setOpacity(opcity);
    }

	float CocoLoadingBar::getTotalWidth()
	{
		return this->m_fTotalLength;
	}
	float CocoLoadingBar::getTotalHeight()
	{
		return this->m_fBarHeight;
	}
}