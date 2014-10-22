#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};

ofVec3f mni2tal(ofVec3f inpoints);
ofVec3f tal2mni(ofVec3f inpoints);


/*
 from http://imaging.mrc-cbu.cam.ac.uk/imaging/MniTalairach
 
 I assumed that the AC was in the correct position in the MNI brain, and therefore that no translations were necessary;
 Assumed that the MNI brain was in the correct orientation in terms of rotation around the Y axis (roll) and the Z axis (yaw);
 Using the SPM99 display tool, I compared the MNI brain to the images in the Talairach atlas;
 Compared to the atlas, the MNI brain seemed tipped backwards, so that the cerebellar / cerebral cortex line in the sagittal view, at the AC, was too low. Similarly, the bottom of the anterior part of the corpus collosum seemed too high. I therefore applied a small (0.05 radian) pitch correction to the MNI brain;
 Matching the top of the MNI brain to the top of the brain in the atlas, required a zoom of 0.92 in Z. Similarly a Y zoom of 0.97 was required as a best compromise in matching the front and back of the MNI brain to the atlas. The left / right match required a 0.99 zoom in X;
 The transform above provided a good match for the brain superior to the AC/PC line, but a poor match below, with the temporal lobes extending further downwards in the MNI brain than in the atlas. I therefore derived a transform for the brain below the AC/PC line, that was the same as the transform above, except with a Z zoom of 0.84;

 --------------------------------------------
 function outpoints = mni2tal(inpoints)
 % Converts coordinates from MNI brain to best guess
 % for equivalent Talairach coordinates
 % FORMAT outpoints = mni2tal(inpoints)
 % Where inpoints is N by 3 or 3 by N matrix of coordinates
 %  (N being the number of points)
 % outpoints is the coordinate matrix with Talairach points
 % Matthew Brett 10/8/99
 
 dimdim = find(size(inpoints) == 3);
 if isempty(dimdim)
 error('input must be a N by 3 or 3 by N matrix')
 end
 if dimdim == 2
 inpoints = inpoints';
 end
 
 % Transformation matrices, different zooms above/below AC
 upT = spm_matrix([0 0 0 0.05 0 0 0.99 0.97 0.92]);
 downT = spm_matrix([0 0 0 0.05 0 0 0.99 0.97 0.84]);
 
 tmp = inpoints(3,:)<0;  % 1 if below AC
 inpoints = [inpoints; ones(1, size(inpoints, 2))];
 inpoints(:, tmp) = downT * inpoints(:, tmp);
 inpoints(:, ~tmp) = upT * inpoints(:, ~tmp);
 outpoints = inpoints(1:3, :);
 if dimdim == 2
 outpoints = outpoints';
 end

 --------------------------------------------
 function outpoints = tal2mni(inpoints)
 % Converts coordinates to MNI brain best guess
 % from Talairach coordinates
 % FORMAT outpoints = tal2mni(inpoints)
 % Where inpoints is N by 3 or 3 by N matrix of coordinates
 %  (N being the number of points)
 % outpoints is the coordinate matrix with MNI points
 % Matthew Brett 2/2/01
 
 dimdim = find(size(inpoints) == 3);
 if isempty(dimdim)
 error('input must be a N by 3 or 3 by N matrix')
 end
 if dimdim == 2
 inpoints = inpoints';
 end
 
 % Transformation matrices, different zooms above/below AC
 rotn = spm_matrix([0 0 0 0.05]);
 upz = spm_matrix([0 0 0 0 0 0 0.99 0.97 0.92]);
 downz = spm_matrix([0 0 0 0 0 0 0.99 0.97 0.84]);
 
 inpoints = [inpoints; ones(1, size(inpoints, 2))];
 % Apply inverse translation
 inpoints = inv(rotn)*inpoints;
 
 tmp = inpoints(3,:)<0;  % 1 if below AC
 inpoints(:, tmp) = inv(downz) * inpoints(:, tmp);
 inpoints(:, ~tmp) = inv(upz) * inpoints(:, ~tmp);
 outpoints = inpoints(1:3, :);
 if dimdim == 2
 outpoints = outpoints';
 end
 */